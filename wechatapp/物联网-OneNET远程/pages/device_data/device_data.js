// pages/device_data/device_data.js
import * as echarts from '../../components/ec-canvas/echarts'
let chart=null
var app = getApp()
// pages/device_data/device_data.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    device_name : "CSDN",
    product_id : "YqRZ5hrM6p",
    start_time : "1711977114000",
    end_time : "1714482714000",
    authInfo : "version=2022-05-01&res=products%2FYqRZ5hrM6p%2Fdevices%2FCSDN&et=2028715245&method=sha1&sign=hRokQQu7H7234O3arME%2F0hpIB2w%3D",
    setUrl: "https://iot-api.heclouds.com/thingmodel/set-device-property",  
    deviceStatusUrl: " ",  //在下方更改
    getDataUrl: " ",
    oneNETData:[],
    deviceStatus: [],
    timer:''
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {
// 生命周期函数--监听页面加载  
    // 构建deviceStatusUrl  
    let deviceStatusUrl = `https://iot-api.heclouds.com/device/status-history?product_id=${this.data.product_id}&device_name=${this.data.device_name}&start_time=${this.data.start_time}&end_time=${this.data.end_time}&limit=100`;  
      
    // 构建getDataUrl  
    let getDataUrl = `https://iot-api.heclouds.com/thingmodel/query-device-property?product_id=${this.data.product_id}&device_name=${this.data.device_name}`;  
      
    // 打印或使用这些URL  
    console.log('deviceStatusUrl:', deviceStatusUrl);  
    console.log('getDataUrl:', getDataUrl);  
    var _this=this
    // 如果需要将构建的URL保存到data中以便后续使用  
    this.setData({  
      deviceStatusUrl: deviceStatusUrl,  
      getDataUrl: getDataUrl ,
        timer: setInterval(function () {
          _this.fetchOnenetData();
          _this.fetchDeviceStatus();
      }, 2000)
    });  
    this.fetchOnenetData();
    this.fetchDeviceStatus();
    this.setOnenetData(13245);
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  },
  // 获取mqtt设备最新属性值
  fetchOnenetData() {
    // 这里应替换为用户的实际鉴权信息
    const authInfo = this.data.authInfo;
    // 构建请求的 URL 
    const url = this.data.getDataUrl;
  
    wx.request({
      url: url,
      method: "GET",
      header: {
        'Authorization': authInfo
      },
      success: (res) => {
        // 更新设备属性值数据
        this.setData({
          onenetData: res.data
        });
        app.TempData=res.data.data[2].value;
         // 打印获取到的设备属性值数据  
        console.log("OneNET数据获取成功：",  app.TempData); 
      },
      fail: (err) => {
        console.log("OneNET数据请求失败");
        console.error(err); // 处理请求失败的情况
      }
    });
  },
  // 获取设备状态历史信息
  fetchDeviceStatus() {
    // 这里应替换为用户的实际鉴权信息
    const authInfo = this.data.authInfo; 
    const url = this.data.deviceStatusUrl;
    wx.request({
      url: url,
      method: "GET",
      header: {
        'Authorization': authInfo
      },
      success: (res) => {
        // 更新设备状态信息数据
        this.setData({
          deviceStatus: res.data
        });
         // 打印获取到的设备属性值数据  
         console.log("OneNET数据获取成功：", res.data); 
      },
      fail: (err) => {
        console.log("设备状态信息请求失败");
        console.error(err); // 处理请求失败的情况
      }
    });
  },
  // 设置设备属性值
  setOnenetData(ledValue) {
    // 以下数据和URL应根据实际情况进行修改
    const authInfo = this.data.authInfo;
    const url = this.data.setUrl;
    const product_id = this.data.product_id;
    const device_name = this.data.device_name;
    // 替换为用户的实际鉴权信息
    wx.request({
      url: url,
      method: 'POST',
      header: {
        'Authorization': authInfo,
      },
      data: {
        "product_id": product_id,
        "device_name":device_name,
        "params": {
          "command": ledValue // 使用传入的ledValue
      },
      success: (res) =>{
        console.log("设备状态信息");
        console.log('完整响应：', res); // 打印完整响应  
        console.log('成功接收数据：', res.data); // 打印接收到的数据 
        //console.log('成功接收数据：', res.data); // 打印接收到的数据
      },
      fail: (err) => {
        console.log("设备状态信息请求失败");
        console.log('请求失败：', err); // 打印错误信息
      }
    }
  });
},
})
function initChart(canvas,width,height,dpr){
  chart=echarts.init(canvas,null,{
    width:width,
    height:height,
    devicePixelRatio:dpr
  })
  canvas.setChart(chart)
  let option=getOption()
  chart.setOption(option)
  return chart
}
function getOption(time,temp){
  return {
    xAxis: {
      type: 'category',
      data: time
    },
    yAxis: {
      type: 'value'
    },
    series: [
      {
        data: temp,
        type: 'line',
        smooth: true
      }
    ]
  }
}