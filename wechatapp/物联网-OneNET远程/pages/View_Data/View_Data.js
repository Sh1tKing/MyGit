var app=getApp();
Page({
    data: {
      temperature:0, //温度
      light:0,//亮度
      fanV:0,//转速
      sliderLEDValue: 0, // 滑块的当前值
      sliderLEDPercent: '0%', // 滑块的百分值显示
      sliderFANValue: 0, // 风扇的当前值
      sliderFANPercent: '0%', // 风扇的百分值显示
    },
    onLoad() {
          //this.fetchOnenetData();
         // this.fetchDeviceStatus();
         this.setData({
           temperature:app.TempData
         })
         
          
    },
    sliderChangeLED: function(e) {
      var value = e.detail.value;
      console.log(value);
      var percent = value + '%'; // 计算百分值，保留两位小数
      this.setData({
        sliderLEDValue: value,
        sliderLEDPercent: percent
      });
    },
    sliderChangeFAN: function(e) {
      var value = e.detail.value;
      console.log(value);
      var percent = value + '%'; // 计算百分值，保留两位小数
      this.setData({
        sliderFANValue: value,
        sliderFANPercent: percent
      });
    }
})
