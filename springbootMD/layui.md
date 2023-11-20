# 方法：layui.define([mods], callback)
通过该方法可在新的 JS 文件中定义一个 layui 模块。参数 mods 是可选的，***用于声明该模块所依赖的模块。*** callback 即为模块加载完毕的回调函数，它返回一个 exports 参数，用于输出该模块的接口。