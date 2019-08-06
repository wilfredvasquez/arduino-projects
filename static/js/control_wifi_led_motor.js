var app = new Vue({
  delimiters: ['[[', ']]'],
  el: "#app",
  data: {
    img_led: false,
    img_fan: false,
    ip_ok: false,
    error: false,
    Url: '',
    dominio:'',
    message_error: '',
  },
  methods: {
    setIP: function(){
      this.dominio = prompt("IP:");
      this.sendRequest("SETIP");
    },
    sendRequest: function(status){
      if (this.dominio == ''){
        alert("First set Arduino's IP");
        return;
      }
      var vue = this;
      changeStatus = "/send/control/led/motor/"+status+"/"+this.dominio;
      axios.get(changeStatus)
      .then(function(response){
        var data = response.data;
        if(data.status=="success"){
          if(status=='FON') vue.img_fan = true;
          if(status=='FOFF') vue.img_fan = false;
          if(status=='ON') vue.img_led = true;
          if(status=='OFF') vue.img_led = false;
          if(status=='SETIP') vue.error = false;
        }
        else{
          vue.message_error = data.message;
          vue.error = true;
        }
      });
    },
  }
});