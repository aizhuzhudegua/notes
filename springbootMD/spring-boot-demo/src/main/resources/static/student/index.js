const path = "/student/info";
layui.use(['table'], function () {
    let table = layui.table;

    /* 初始化表格 */
    table.render(tableOptions());

    /* 表头事件监听 */
    toolBar(table);

    /* 操作栏监听 */
    tool(table);

});

/**
 * 数据表格查询条件(必须有,不然表格重载不了)
 */
function queryWhere() {
    let name = $("#name").val();
    let schoolId = $("#schoolId").val();
    let academyId = $("#academyId").val();
    let sex = $("#sex").val();
    return {
        name: name,
        schoolId: schoolId,
        academyId: academyId,
        sex: sex,
    }
}

/**
 * 刷新表格数据
 * @param table
 */
function reloadTableData(table) {
    if (null === table || undefined === table) {
        table = layui.table;
    }
    let p = tableOptions();
    p.where = queryWhere();
    p.page.curr = 1;
    table.reloadData(p.id, p);
}

/**
 * 表头操作
 * @param table
 */
function toolBar(table) {
    table.on('toolbar(layFilter)', function (obj) {
        if ('search' === obj.event) {
            reloadTableData(table);
        }
        if ('saveStudentInfo' === obj.event) {
            layer.open({
                type: 2,
                title: '新增',
                content: path + '/add',
                area: ['60%', '80%'],
                fix: false,
                maxmin: false,
                shade: 0.3,
                shadeClose: false,
                success: function (layero, index) {
                    layer.iframeAuto(index);
                },
            });


        }
    })
}

/**
 * 表格操作
 * @param table
 */
function tool(table) {
    table.on('tool(layFilter)', function (obj) {
        console.log('tool ==> obj', obj);

        let data = obj.data;
        if ('delete' === obj.event) { // 删除
            let msg = '确定删除【' + data.name + '】信息吗？';
            layer.confirm('<div style="color: #ff000c">' + msg + '</div>', {
                icon: 3,
                title: '系统提示！'
            }, function () {
                $.ajax({
                    type: 'delete',
                    url: path + '/' + data.id,
                    success: function (res) {
                        if (res.success) {
                            reloadTableData(table); // 删除成功, 刷新表格
                            layer.msg(res.msg, {icon: 1, time: 1500});
                        } else {
                            layer.msg(res.msg, {icon: 1, time: 1500});
                        }
                    }
                })
            });
        }
        if ('update' === obj.event) { // 更新
            layer.open({
                type: 2,
                title: '编辑',
                content: path + '/edit/' + data.id,
                area: ['60%', '80%'],
                fix: false,
                maxmin: false,
                shade: 0.3,
                shadeClose: false,
                success: function (layero, index) {
                    layer.iframeAuto(index);
                },
            });
        }
        if ('view' === obj.event) { // 查看
            layer.open({
                type: 2,
                title: '查看学生信息',
                content: path + '/view/' + data.id,
                area: ['60%', '80%'],
                fix: false,
                maxmin: false,
                shade: 0.3,
                shadeClose: false,
                btn: ['关闭'],
                success: function (layero, index) {
                    layer.iframeAuto(index);
                },
            });
        }
    })
}

/**
 * 表格参数初始化
 */
function tableOptions() {
    return {
        url: path + "/page",
        where: queryWhere(),
        cols: [[
            {field: 'name', title: '姓名', align: "center"},
            {
                field: 'schoolId', title: '所属学校', align: "center", templet: function (d) {
                    return viewSchool(d.schoolId);
                }
            },
            {
                field: 'academyId', title: '所属学院', align: "center", templet: function (d) {
                    return viewAcademy(d.academyId);
                }
            },
            {field: 'birthday', title: '出生日期', align: "center"},
            {field: 'stuNo', title: '学号', align: "center"},
            {
                field: 'sex', title: '性别', align: "center", templet: function (d) {
                    return viewSex(d.sex);
                }
            },
            {fixed: 'right', title: '操作', toolbar: '#toolbarHandle', width: "20%", align: "center"}
        ]],
        id: 'layTable',
        elem: '#layTable',
        toolbar: '#toolbar',
        layFilter: 'layFilter',
        defaultToolbar: ['filter', 'exports', 'print'],
        cellMinWidth: 80,
        response: {
            statusName: 'status', //规定数据状态的字段名称，默认：code
            statusCode: 200 //规定成功的状态码，默认：0
        },
        parseData: function (res) { //res 即为原始返回的数据
            return {
                "status": res.status, //解析接口状态
                "msg": res.message, //解析提示文本
                "count": res.data.total, //解析数据长度
                "data": res.data.rows //解析数据列表
            };
        },
        page: {
            theme: '#1E9FFF',
            groups: 5,
            limits: [10, 15, 30, 50, 100, 500, 10000],
            layout: ['prev', 'page', 'next', 'skip', 'refresh', 'limit', 'count'],
            prev: '上一页',
            next: '下一页'
        },
    }
}


/**
 * 回显学校名称
 * @param id
 * @returns {string}
 */
function viewSchool(id) {
    if ('0' === id) {
        return '湖北大学';
    }
    return '';
}

/**
 * 回显学院信息
 * @param id
 * @returns {string}
 */
function viewAcademy(id) {
    if ('1' === id) {
        return '计算机与信息工程学院';
    }
    if ('2' === id) {
        return '数学与统计学学院';
    }
    if ('3' === id) {
        return '材料科学与工程学院';
    }
    return '';
}

function viewSex(value) {
    if ('1' === value) {
        return '男';
    }
    if ('2' === value) {
        return '女';
    }
    return '未知';
}

