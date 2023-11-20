package com.github.itdachen.sdk.query;

import java.io.Serializable;


/**
 * 学生信息表 查询参数
 *
 * @author 王大宸
 * @date 2023-08-12 21:48:33
 */
public class StudentInfoQuery implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 查询页数
     */
    private Integer page = 1;

    /**
     * 分页查询条数
     */
    private Integer limit = 10;

    /**
     * 姓名
     */
    private String name;

    /**
     * 所属学校
     */
    private String schoolId;

    /**
     * 所属学院
     */
    private String academyId;

    /**
     * 性别
     */
    private String sex;

    public Integer getPage() {
        return page;
    }

    public void setPage(Integer page) {
        this.page = page;
    }

    public Integer getLimit() {
        return limit;
    }

    public void setLimit(Integer limit) {
        this.limit = limit;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSchoolId() {
        return schoolId;
    }

    public void setSchoolId(String schoolId) {
        this.schoolId = schoolId;
    }

    public String getAcademyId() {
        return academyId;
    }

    public void setAcademyId(String academyId) {
        this.academyId = academyId;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }
}
