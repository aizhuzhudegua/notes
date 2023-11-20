package com.github.itdachen.service;

import com.github.itdachen.common.response.TableData;
import com.github.itdachen.sdk.dto.StudentInfoDTO;
import com.github.itdachen.sdk.query.StudentInfoQuery;
import com.github.itdachen.sdk.vo.StudentInfoVO;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 21:50
 * Created with IntelliJ IDEA.
 */
public interface IStudentInfoService {

    /***
     * 分页查询
     *
     * @author 王大宸
     * @date 2023/8/12 22:27
     * @param query query
     * @return com.github.itdachen.common.response.TableData<com.github.itdachen.sdk.vo.StudentInfoVO>
     */
    TableData<StudentInfoVO> findStudentInfoPage(StudentInfoQuery query) throws Exception;

    /***
     * 新增学生信息
     *
     * @author 王大宸
     * @date 2023/8/12 23:30
     * @param studentInfoDTO studentInfoDTO
     * @return com.github.itdachen.sdk.vo.StudentInfoVO
     */
    StudentInfoVO saveStudentInfo(StudentInfoDTO studentInfoDTO) throws Exception;

    /***
     * 根据ID查询
     *
     * @author 王大宸
     * @date 2023/8/13 16:36
     * @param id id
     * @return com.github.itdachen.sdk.vo.StudentInfoVO
     */
    StudentInfoVO getStudentInfoById(String id) throws Exception;

    /***
     * 更新学生信息
     *
     * @author 王大宸
     * @date 2023/8/13 16:39
     * @param studentInfoDTO studentInfoDTO
     * @return com.github.itdachen.sdk.vo.StudentInfoVO
     */
    StudentInfoVO updateStudentInfo(StudentInfoDTO studentInfoDTO) throws Exception;


    /***
     * 删除学生信息
     *
     * @author 王大宸
     * @date 2023/8/13 16:37
     * @param id id
     * @return void
     */
    void deleteStudentInfoById(String id) throws Exception;


}
