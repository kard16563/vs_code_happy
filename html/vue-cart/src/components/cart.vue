<template>
    <div>
        <p>=============</p>

        <p>cart from new vue conpents _>_>_ ==>></p>
        <br>
        <p>{{name}}</p>
        <br>
        <table border="1">
           <tr>
               <th>#</th>
               <th>name</th>
               <th>unit-price</th>
               <th>quantity</th>
               <th>total price</th>
           </tr>

           <tr v-for="(c,i) in cart" :key="c.id" :class="{active:c.active}" >
               <!---class 动态样式---- :class="{active:c.active}"----->
               <td>
                   <input type="checkbox" v-model="c.active" > <!----v-model="c.active"-双向绑定-->
               </td>
               <td> {{c.text}}</td>
               <td> {{c.price}}</td>
               <td> <button @click="minus(i)" >-</button> 
                    {{c.count}}
                    <button @click="add(i)">+</button>
                </td>
               <td> {{c.price*c.count}}</td><!---支持运算-->
           </tr>

           <tr>
               <td>123</td><!--复杂计算-->
               <td colspan="2" >{{activecount}}/{{count}}</td>
               <td colspan="2" >mon_{{total}}</td>
           </tr>

        </table>


    </div>
</template>

<script>

    export default {
        //props :['name','cart'],//接收参数 对应 父的<Car>  ----->4
        //props:['name'],// 新添加 ------》4
        props:{//数据持久化----localStorage 形式暂存防止刷新数据丢失 ----1
                name: { type :String,required: true}
        },
        
        data() {//  新加 --------->5
            return {
                //cart: [],
                cart:JSON.parse(localStorage.getItem('cart')) || []
                //localStorage 形式暂存防止刷新数据丢失
                //JSON.parse(localStorage.getItem('cart'))对cart进行初始化确保数据可以回来
            };
        },
        watch:{//数据持久化---localStorage 形式暂存防止刷新数据丢失-----2
            cart:{
                handler(n,o){//数据发生变化就执行本 函数 n：新的值 o：老的值
                    localStorage.setItem('cart',JSON.stringify(n));
                    window.console.log(o);
                    //localstorage中的名字为cart 以json的形式字符串进行序列化（n） 然后放入 
                },
                deep:true//obj 深层次的值发生变化也会触动 handler函数
            }
        },

        created () {// 新加 一次性的 -------->
        //监听APP.vue添加的事件
        this.$bus.$on('addcart',good=>{

            const res =this.cart.find(v=>v.id===good.id);//exit in cart?
            if (res) {//have exited in cart 
                res.count=res.count+1;//若存在数目变化
                
            }else{
                this.cart.push({ //this.goods.push--改为这个表示向cart中进行push添加
                ...good,//good 呢一套 text and price
                count:1,
                active: true//复选框
                });
            }

        })//$on进行事件监听
            
        },


        methods: {
            minus(i) {
                const count  = this.cart[i].count ;//定义常量
                if (count>1) {
                    this.cart[i].count-=1;
                } else {
                    this.remove(i);
                }
            },

            add(i){
                this.cart[i].count+=1;
            },

            remove (i) {
                if (window.confirm('确定删除吗？')) {
                    this.cart.splice(i,1);
                }
            },

        },
         computed: {//希望产生一些新属性 加到 父类传进来的 
             //复杂计算属性 -需要额外加工data中数据的时候使用
             activecount() {
                 //过滤合格的长度
                 //this.cart.filter(v=>v.active) 过滤v.active 为true的
                 return this.cart.filter(v=>v.active).length; 
             },
             count(){//calculate the num  of activity obj
                 return this.cart.length;
             },
             total(){//计算激活总price

                 let num=0;
                 this.cart.forEach(c => {//遍历
                 if (c.active) {//如果激活
                         num += c.price + c.count;
                     }
                    
                });
                return num;
            }

        },
        
    }
</script>

<style scoped>
.active{
    color: greenyellow;
}

</style>