<template>
    <form>
        <slot></slot>
    </form>
</template>

<script>
    export default {
        provide(){// 传给后代
            return{
                form : this //将 本实例 传出 后代可以用from 获取model 和 rules
            };

        },
        props: {
            model: {
                type: Object,
                required: true
            },
            rules:{
                type:Object
            },

        },

        created(){  // self_from_item   先创建后挂载  先于mounted发生
        this.fields=[];//将监听内容进行缓存
        this.$on('from_item',item=>this.fields.push(item))//监听

        },
        methods: {
            async validate(callback) {// callback 当外界调用的时候可以传入一个回调函数
                //去除缓存的所以的值
                // formitem 数组转换为 validate() 返回 promise数组
                const tasks = this.fields.map(item=>item.validate());//调用46行 in self-from——item
                window.console.log('self_form _> task--->> ',tasks);
                // 将所有结果统一
                const results = await Promise.all(tasks);//异步处理 这里面全是true false的数组
                let res = true;
                results.forEach(valid => {
                    if (!valid){
                        res =false;//遍历所有 其中有一个都不行

                    }
                });
                callback(res);
            }
        },
        
    }
</script>

<style scoped>

</style>