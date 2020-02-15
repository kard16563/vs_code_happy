<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <HelloWorld msg="Welcome to Your Vue.js App"/>
    <p v-if="showname">{{name}}</p><!---判断--->

    <!-- <p>
      <input v-model="text" type="text"  /> --双向监听---
      <button @click="addgood">123</button>
    </p> -->
     <p> {{foo.ba}} ***==== new---- {{foo.abc}}</p>
     <el-button> button </el-button>
     <br>

     <win> 
       <template slot='head' > <h3>head 有名插入 </h3> </template>
        自定义组件的插槽  ---- 匿名
      <template slot='foot'> <h3> 有名插入 </h3> 
                              <button>sure ? </button> 
      </template>
      </win>

    
    <ul>
      <!--   <li v-for="good in goods" :key="good.id">  - -->
      <li v-for="(good,index) in goods" :key="good.id"> 
        <!--:key 动态赋值 key的值可以边 key=可就是固定的---->
        <span>{{good.text}} 索引：{{index}} </span>
        <span> {{good.price}} 索引：{{index}}</span>
        <button @click="addgood2(index)" >buttons</button><!--传递ID--->
       
      </li>
    </ul>

    
   

    <!---导入新的组件 --->    
<!----    <cart :name='name' :cart='cart' ></cart>  -----3------>
    <!--传入参数名为 name cart 传给组件的东西 -->
    <cart :name="name" ></cart><!-- 添加 3 -->

    <!-- element 测试 --->
    <formtest title="element 表单 父类传 " :tit='titvar' ></formtest> 
    <!----父类传参 静态title="props['title']" 动态传:tit='titvar'值在data中 --->

    <msg_from_children @message_from_button_child='click_msg_from_child'></msg_from_children>

    <!----接收来自子类的 消息 @子类中的事件 在method中添加click_msg_from_child --->
    <p>5555555555555</p>
    <self_test></self_test>



  </div>

  


</template>

<script>
import HelloWorld from './components/HelloWorld.vue'//局部导入组件
import cart from './components/cart.vue';//导入组件 名为 cart
import formtest from "./components/formtest";
import msg_from_children from './components/button';
import win from './components/win';
import self_test from'./components/diy_compon'

//import { setTimeout } from 'timers'
import axios from 'axios'//加载axios 
export default { //--->组件
  
  name: 'app',
  provide(){ 
    return {
      somevalue:'祖先的消息---->  '
    }

  },

  data(){
    return{
      self_messgae:'hahaha555555',
      //self_messgae
      titvar:'dynamic state 动态赋值 父类传',
      name:'123456,vue',
      foo:{ba:'bar'},
      showname :false,
      goods: [
        // {id:1,text:'1---',price:551}, //做假数据 已被放入vue.config.js 文件
        // {id:2,text:'2---',price:552},
        // {id:3,text:'3---',price:553},
        // {id:4,text:'4---',price:554},
        // {id:5,text:'5---',price:555},
      ],
      text : '',
      //cart:[]---------->用于无关vue通信----------2
    }
      
  },
  components: {
    HelloWorld,
    cart, //等价于 key velue 都是cart --> key 为value 上面可以使用<cart></cart>
    formtest,
    msg_from_children,
    win,
    self_test
  },
  async created(){//创建钩子 组件完成执行一次  async-->异步
    this.$set(this.foo,'abc','aa')// 为foo 添加新的 {abc:'aa'}属性

    setTimeout(()=>{//函数
      this.showname=true;
    },2000);


    try {
      // 查询数据 npm i axios -s 
    const response = await axios.get('/app/goods'); //await 必须跟 async 
    //要使用 await 其后面的函数要返回 promise对象
    //表示 异步 返回路由信息 保存到ret 中
    window.console.log(response);
    this.goods = response.data.list;//从res response 中的data返回list 给goods\
    //list 与 vue.config.js 的 list 匹配
    
      
    } catch (error) {//错误输出地方
      
    }

    

  },

  methods: {//函数

  click_msg_from_child(obj){//子类 通过事件传递参数为obj
    window.confirm(obj.msg);
    window.console.log(obj);

  },
    // addgood() {
    //   this.goods.push({
    //     text: this.text,//双向绑定输出
    //     price:1000
    //   })      
    // },
    addgood2(i){
      //根据ID查询
      const good =this.goods[i];

      this.$bus.$emit('addcart',good);
      // 事件名 和 传递的值----->用于vue 没有任何关系的vue之间的通信
      //有这个就要把下面的移动走----------------1

      // const res =this.cart.find(v=>v.id===good.id);//exit in cart?
      // if (res) {//have exited in cart 
      // res.count=res.count+1;//若存在数目变化
        
      // }else{
      //   this.cart.push({ //this.goods.push--改为这个表示向cart中进行push添加
      //     ...good,//good 呢一套 text and price
      //     count:1,
      //     active: true//复选框
      //   });
      // }

    }
  },
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}



</style>