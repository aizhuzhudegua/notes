package com.github.itdachen.sdk.vo;

import java.io.Serializable;


/**
 * 学生信息表 VO
 *
 * @author 王大宸
 * @date 2023-08-12 21:48:33
 */
public class StudentInfoVO implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 主键唯一标识
     */
    private String id;

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
     * 出生日期
     */
    private String birthday;

    /**
     * 学号
     */
    private String stuNo;

    /**
     * 性别
     */
    private String sex;

    /**
     * 描述
     */
    private String remarks;


    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setSchoolId(String schoolId) {
        this.schoolId = schoolId;
    }

    public String getSchoolId() {
        return schoolId;
    }

    public void setAcademyId(String academyId) {
        this.academyId = academyId;
    }

    public String getAcademyId() {
        return academyId;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    public String getBirthday() {
        return birthday;
    }

    public void setStuNo(String stuNo) {
        this.stuNo = stuNo;
    }

    public String getStuNo() {
        return stuNo;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getSex() {
        return sex;
    }

    public void setRemarks(String remarks) {
        this.remarks = remarks;
    }

    public String getRemarks() {
        return remarks;
    }

}
