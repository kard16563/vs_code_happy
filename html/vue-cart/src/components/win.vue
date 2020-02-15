<template>
    <div class="windows"><!---用在APP.vue中--->
            <br> <slot name="head" ></slot><br >
        <div class="head">head 页头</div>
            <slot></slot> <!--自定义组件的插槽 类似以内存条 用于扩展--->
        <div class="foot">foot 页脚</div>
            <br><slot name='foot' ></slot>
    
    </div>
    
</template>

<script>
    export default {
        
    }
</script>

<style>

</style>