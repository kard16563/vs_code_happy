import Vue from 'vue'//原来的在 node_modles 中  import 模块名 from 路径
import App from './App.vue' // ./表示自己的创建的文件  ./->当前目录下
import './plugins/element.js'//在这里引入 element-UI的js文件

//修改vue的原型 目的是建立总线 两个无任何关系的vue文件之间的通信
//Vue.config.productionTip = false
Vue.prototype.$bus=new Vue();
//用于传递消息 添加新属性 叫bus用于文件间 的消息 扩展vue ---》消息总线

Vue.component('kard-comp',{})//全局注册组件
//自定义组件 一次定义可以多次使用 name->kard-comp  config->{}

new Vue({//新new的 具有上面的的新属性
  render: h => h(App),// 渲染操作 render --》render APP组件  
}).$mount('#app')//挂载 mount到 public 下的index.html
