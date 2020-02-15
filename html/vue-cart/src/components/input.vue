<!---自定义组件--->
<template>
    <!----<input type="text" :value="input_value" @input="input_handler" > old ---->
    <div>
        {{somevalue}}<input :type="type" :value="input_value" @input="input_handler" >
    </div>
</template>

<script>
    export default {

        inject:['somevalue'],//直接接收来自祖先的消息

        props:{//reserve the data from father
            value:{
                type:String,
                default:'' 
                },
            type:{ //新加的
                type:String,
                default:'text'
            }
        },//以对象的关系 {} 进行限定
        data() {
            return {//单数据流原则： 组件内不能修改propos属性
                input_value: this.value// 这个是父类传过来的值 此处无法更改
            }
        },
        methods: {
            input_handler(e) {//change the value---->receive 接收 the event
                this.input_value=e.target.value;//进行更改
                window.console.log('input changeto  ---> ',this.input_value);
                // inform the father component that the things is changed
                //告诉父组件 东西已修改
                this.$emit('input',this.input_value);// pass the new data to father component
                // input -- 返回给 父的input 比较简洁 反之父还要另加 东西 

                //  将变化传给 formitem 尤其判定是否合法 将信息传给父类
                this.$parent.$emit('valid',this.input_value)//让父类派发消息 
                // this.input_value 本值 
                // 父类有一个槽位 没办法 @进行监听 只能让父类发消息 父类自己接受
            }
        },
        
    }
</script>

<style>

</style>