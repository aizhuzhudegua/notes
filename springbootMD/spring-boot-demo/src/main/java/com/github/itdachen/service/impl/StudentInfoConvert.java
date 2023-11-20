package com.github.itdachen.service.impl;

import com.github.itdachen.entity.StudentInfo;
import com.github.itdachen.sdk.dto.StudentInfoDTO;
import com.github.itdachen.sdk.vo.StudentInfoVO;

/**
 * 学生信息表 类型转换
 *
 * @author 王大宸
 * @date 2023-08-12 21:48:33
 */
public class StudentInfoConvert {

    public static StudentInfo toJavaObject(StudentInfoDTO StudentInfoDTO) {
        if (null == StudentInfoDTO) {
            return null;
        }
        StudentInfo studentInfo = new StudentInfo();
        studentInfo.setId(StudentInfoDTO.getId());
        studentInfo.setName(StudentInfoDTO.getName());
        studentInfo.setSchoolId(StudentInfoDTO.getSchoolId());
        studentInfo.setAcademyId(StudentInfoDTO.getAcademyId());
        studentInfo.setBirthday(StudentInfoDTO.getBirthday());
        studentInfo.setStuNo(StudentInfoDTO.getStuNo());
        studentInfo.setSex(StudentInfoDTO.getSex());
        studentInfo.setRemarks(StudentInfoDTO.getRemarks());
        return studentInfo;
    }

    public static StudentInfoVO toJavaObjectVo(StudentInfo studentInfo) {
        if (null == studentInfo) {
            return null;
        }
        StudentInfoVO StudentInfoVO = new StudentInfoVO();
        StudentInfoVO.setId(studentInfo.getId());
        StudentInfoVO.setName(studentInfo.getName());
        StudentInfoVO.setSchoolId(studentInfo.getSchoolId());
        StudentInfoVO.setAcademyId(studentInfo.getAcademyId());
        StudentInfoVO.setBirthday(studentInfo.getBirthday());
        StudentInfoVO.setStuNo(studentInfo.getStuNo());
        StudentInfoVO.setSex(studentInfo.getSex());
        StudentInfoVO.setRemarks(studentInfo.getRemarks());
        return StudentInfoVO;
    }


}