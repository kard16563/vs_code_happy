<template>
<!---这里自定义一个 formitem 有 label， props ，还有input 的槽位  ---->
    <div>
        <label v-if="lable">{{lable}}</label>
        
        <div>
            <slot></slot>
            <p v-if="valid_data=='error'" class="error">{{errormag}}</p>
        </div>

    </div>
</template>

<script>

    //导入 
    import schema from 'async-validator'//导入校验依赖


    export default {
        inject:['form'],// 接受 来自 self_form.vue 的消息 
        props:['lable','prop'],
        data() {
            return {
                valid_data: '',
                errormag:'',
            }
        },
        created(){

            this.$on('valid',this.validate)// 自身监听
            // 触发 validata方法 处理自身传来的数据 来自input.vue

        },

        mounted(){
            //生命周期  挂载到form上 派发一个添加事件 挂上的才会去做校验 本例子中有prop就校验
            //别的像button 就不行
            if (this.prop) {//给self——from
                this.$parent.$emit('from_item',this);//将自己传递出去
            }
        },

        methods:{
            validate(  ){// 异步前这边有个value 
                // 异步的值都要 promise
                    return new Promise(resolve=>{

                        //进行校验当前项  使用async-validate模块  element-UI 上面有
                    const descriptor ={
                        [this.prop]:this.form.rules[this.prop]
                    //this.form.rules 返回为 key-value [key] 当前项---> [key]:rules[key]
                    };
                    const validator = new schema(descriptor);//校验器  校验方法
                    validator.validate({[this.prop]:this.form.model[this.prop] },errors =>{
                        // this.form.model[this.props] 获取value
                        //进行异步校验 1 校验的值,2 错误返回的东西
                        //window.console.log('异步校验---》'.this.prop);
                        if (errors) {
                            //校验失效
                            this.valid_data = 'error';
                            this.errormag = errors[0].message;//.message 调信息

                            resolve(false);// 父拿到值 为 Promise false

                        } else {
                            this.valid_data = '';
                            this.errormag = '';//.message 调信息

                            resolve(true);

                        }


                    } );


                    })

                    // //进行校验当前项  使用async-validate模块  element-UI 上面有
                    // const descriptor ={
                    //     [this.prop]:this.form.rules[this.prop]
                    // //this.form.rules 返回为 key-value [key] 当前项---> [key]:rules[key]
                    // };
                    // const validator = new schema(descriptor);//校验器  校验方法
                    // validator.validate({[this.prop]:value },errors =>{
                    //     //进行异步校验 1 校验的值,2 错误返回的东西
                    //     //window.console.log('异步校验---》'.this.prop);
                    //     if (errors) {
                    //         //校验失效
                    //         this.valid_data = 'error';
                    //         this.errormag = errors[0].message;//.message 调信息

                    //     } else {
                    //         this.valid_data = '';
                    //         this.errormag = '';//.message 调信息

                    //     }


                    // } )

            }

        },
        
    }
</script>

<style scoped>
.error{
    color: blueviolet;
}

</style>