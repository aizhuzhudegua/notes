package com.github.itdachen.common.response;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 * Description: 分页数据返回格式
 * Created by 王大宸 on 2023-08-12 17:07
 * Created with IntelliJ IDEA.
 */
public class TableData<T> implements Serializable {
    private static final long serialVersionUID = 6361435953431364220L;
    /**
     * 数据总条数
     */
    long total = 0;
    /**
     * 查询返回数据
     */
    List<T> rows = new ArrayList<>();

    public TableData(long total, List<T> rows) {
        this.total = total;
        this.rows = rows;
    }

    public TableData() {
    }

    public long getTotal() {
        return total;
    }

    public void setTotal(long total) {
        this.total = total;
    }

    public List<T> getRows() {
        return rows;
    }

    public void setRows(List<T> rows) {
        this.rows = rows;
    }

}
