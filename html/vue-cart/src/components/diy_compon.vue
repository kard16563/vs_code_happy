<template>
    <div>
        <h1>****----------- self_compon 01 ----------**** </h1>
        

        <div> <!---->
      <div id='self_1'>
            <span v-bind:title="self_messgae" >鼠标悬停几秒钟查看此处动态绑定的提示信息！
            </span>

        <!-- <input v-model= "self_messgae">
        <p>{{self_messgae}} </p> -->
        
        <p><br>9999999</p>
        <p>{{self_messgae}}</p>
        <input v-model="self_messgae">
        
      </div>

      <todolist v-for="good in goods"  v-bind:key='good.id'  v-bind:todo='good'>
      </todolist>
    </div>

        <button @click='change'>bbbb </button>
      <button :disabled='diss'>butt</button>

    <input v-model="reversed">
    <p>Computed reversed message: "{{ reversedMessage }}"</p>
    <div  class="static" :class="{ active: isactive,'123':true}" >class change</div>
    <p :class='append'>class change 2</p>
    <p :style="{ color:active_color,fontSize:fontSize+'px' }">set style</p>
  <p v-bind:style="obj_style">set style2</p> 
  
  <template v-if="loginType === 'username'">
  <label>Username</label>
  <input v-model="loginType"  placeholder="Enter your username">
</template>
<template v-else>
  <label>Email</label>
  <input  v-model="loginType" placeholder="Enter your email address">
</template>

    <div>
        <button @click='array_set'>array set</button>
    <span v-if="items.length" ></span>
    <div v-for="(i,index) in items" :key='i.id' >
        <span> {{index}}--- {{i}}---{{i.name}}</span>
    </div>
    
    <p >{{items}}</p>
    </div>
    <button @click='array_foreach' >array_foreach</button>
    


    </div>
</template>

<script>

import todolist from'./diy_compon2'
    export default {

       components:{
            todolist,
       },

        data() {
            return {
                items: [
                    {a:'a',name:'aa'}, 
                    {a:'b',name:"bb"}, 
                    {a:'c',name:"cc"}
                    ],
                loginType:'username',
                obj_style:{
                    color: 'green',
                    fontSize: '64px'
                },
                active_color:'red',
                fontSize: 60,

                append:{
                    happy:true,
                    sad:false,
                },
                isactive:true,
                reversed:'www.cctv.com',
                diss:555,
                self_messgae: '55555',
                goods:[
                    {id:0,text:'123'},
                    {id:1,text:'1234'},
                    {id:2,text:'1235'},
                    {id:3,text:'1236'},
                ],


            }
        },
        watch:{
            reversed(){
              window.console.log('reversed value is change--->') 
              this.bbbb()
            },

        },
        methods: {
            bbbb(){
                alert('5555555')
                window.console.log('bbb55555555')

            },
            change(){// change the value
                if(this.isactive==true){
                    this.isactive=false
                }else{
                    this.isactive=true
                }
            },
            array_set(){
                //this.$set(this.items,1,'bababa','cbb')
                this.items.splice(1,0,{a:'0a',name:'00aa'})//add the value---1
                //position ,delete? 0-> no 1->yes,values
                this.$set(this.items,3,{a:'1cc0a',name:'1cc00aa'})//add the value---1
                

                alert(this.items)
                


            },
            array_foreach(){
                this.items.forEach(it=>{
                    window.console.log('before_ for->each',
                        it.name,it.a,it.name,it.age,it.favoriteColor)

                     Object.assign(it, {
                         age: 27,
                         favoriteColor: 'Vue Green'
                         })

                    window.console.log('after_ for->each',
                        it.name,it.a,it.name,it.age,it.favoriteColor)
                    })


            },
        },
        created(){
            //console.log('55555')
            window.console.log('>>>----diy_self_message---->',
                this.self_messgae)
        },
        computed:{
            reversedMessage(){
                return this.reversed.split('').reverse().join('')

            }
        }


        
    }
</script>

<style>

</style>