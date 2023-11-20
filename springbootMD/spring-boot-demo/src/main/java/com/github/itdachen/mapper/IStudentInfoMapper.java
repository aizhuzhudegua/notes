package com.github.itdachen.mapper;

import com.github.itdachen.entity.StudentInfo;
import com.github.itdachen.sdk.query.StudentInfoQuery;
import com.github.itdachen.sdk.vo.StudentInfoVO;

import java.util.List;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 18:06
 * Created with IntelliJ IDEA.
 */
public interface IStudentInfoMapper {

    /***
     * 测试查询学生数量
     *
     * @author 王大宸
     * @date 2023/8/12 18:23
     * @return java.lang.Integer
     */
    Integer findCount();

    /***
     * 查询数据
     *
     * @author 王大宸
     * @date 2023/8/12 22:30
     * @param query query
     * @return java.util.List<com.github.itdachen.sdk.vo.StudentInfoVO>
     */
    List<StudentInfoVO> findStudentInfoList(StudentInfoQuery query);

    /***
     * 查询条数
     *
     * @author 王大宸
     * @date 2023/8/12 22:30
     * @param query query
     * @return java.lang.Long
     */
    Long findStudentInfoCount(StudentInfoQuery query);

    /***
     * 新增学生信息
     *
     * @author 王大宸
     * @date 2023/8/12 0:06
     * @param studentInfo studentInfo
     * @return void
     */
    void saveStudentInfo(StudentInfo studentInfo);
    
    /***
     * 根据ID查询
     *
     * @author 王大宸
     * @date 2023/8/13 16:36
     * @param id id
     * @return com.github.itdachen.sdk.vo.StudentInfoVO
     */
    StudentInfoVO getStudentInfoById(String id);


    /***
     * 更新学生信息
     *
     * @author 王大宸
     * @date 2023/8/13 16:37
     * @param studentInfo studentInfo
     * @return void
     */
    void updateStudentInfo(StudentInfo studentInfo);
    
    
    /***
     * 删除学生信息
     *
     * @author 王大宸
     * @date 2023/8/13 16:37
     * @param id id
     * @return void
     */
    void deleteStudentInfoById(String id);
    

}
