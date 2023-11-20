layui.use(['form', 'laydate'], function () {
    let form = layui.form;
    let laydate = layui.laydate;
    form.render();

    /* 出生日期, 日期选择组件 */
    laydate.render({
        elem: '#birthday'
    });


    /* 提交 */
    form.on('submit(editStudentInfo)', function (data) {
        $.ajax('/student/info/' + data.field.id, {
            type: 'PUT',
            data: JSON.stringify(data.field),
            contentType: 'application/json',
            datatype: 'json',
            success: function (res) {
                if (200 === res.status) {
                    // 刷新父页面表格
                    parent.reloadTableData();

                    /* 弹窗提示操作成功 */
                    layer.alert(res.msg, {title: "系统提示", icon: 1}, function () {
                        /* 关闭当前弹窗 */
                        parent.layer.close(parent.layer.getFrameIndex(window.name));
                    });

                } else {
                    layer.alert(res.msg, {
                        icon: 2,
                        title: "系统提示",
                        btn: ['确认'], btnclass: ['btn btn-primary'],
                    });
                }
            }
        })

        // 防止 form 跳转
        return false;
    });


    /* 关闭弹窗 */
    $("#buttonClose").click(function () {
        parent.layer.close(parent.layer.getFrameIndex(window.name));
    });

});
