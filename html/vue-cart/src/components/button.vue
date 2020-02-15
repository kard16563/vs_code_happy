<template>
    <button @click="sub">  子类传参给父类 </button>

    
</template>

<script>
    export default {
      methods: {
          sub() {
              this.$emit('message_from_button_child',{msg:'message from children'})
              //子类传参给父类 事件名为 message_from_button_child 消息为{msg:'message from children'}
          }
      },
      
    }
</script>

<style>

</style>