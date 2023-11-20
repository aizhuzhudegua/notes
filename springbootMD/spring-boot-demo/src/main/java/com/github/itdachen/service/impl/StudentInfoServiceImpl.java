package com.github.itdachen.service.impl;

import com.github.itdachen.common.exception.BizException;
import com.github.itdachen.common.response.TableData;
import com.github.itdachen.entity.StudentInfo;
import com.github.itdachen.mapper.IStudentInfoMapper;
import com.github.itdachen.sdk.dto.StudentInfoDTO;
import com.github.itdachen.sdk.query.StudentInfoQuery;
import com.github.itdachen.sdk.vo.StudentInfoVO;
import com.github.itdachen.service.IStudentInfoService;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 21:51
 * Created with IntelliJ IDEA.
 */
@Service
public class StudentInfoServiceImpl implements IStudentInfoService {

    private final IStudentInfoMapper studentInfoMapper;

    public StudentInfoServiceImpl(IStudentInfoMapper studentInfoMapper) {
        this.studentInfoMapper = studentInfoMapper;
    }

    /***
     * 分页查询
     *
     * @author 王大宸
     * @date 2023/8/12 22:27
     * @param query query
     * @return com.github.itdachen.common.response.TableData<com.github.itdachen.sdk.vo.StudentInfoVO>
     */
    @Override
    public TableData<StudentInfoVO> findStudentInfoPage(StudentInfoQuery query) throws Exception {
        query.setPage(query.getPage() > 0 ? (query.getPage() - 1) * query.getLimit() : 0);
        List<StudentInfoVO> list = studentInfoMapper.findStudentInfoList(query);
        Long appClientLimit = studentInfoMapper.findStudentInfoCount(query);
        return new TableData<StudentInfoVO>(appClientLimit, list);
    }

    /***
     * 新增学生信息
     *
     * @author 王大宸
     * @date 2023/8/12 23:30
     * @param studentInfoDTO studentInfoDTO
     * @return com.github.itdachen.sdk.vo.StudentInfoVO
     */
    @Override
    @Transactional(rollbackFor = Exception.class)
    public StudentInfoVO saveStudentInfo(StudentInfoDTO studentInfoDTO) throws Exception {

     //   throw new BizException("这里出现了一个异常!!!");


        StudentInfo studentInfo = StudentInfoConvert.toJavaObject(studentInfoDTO);

        studentInfo.setId(UUID.randomUUID().toString().replaceAll("-", ""));
        studentInfo.setCreateTime(LocalDateTime.now());
        studentInfo.setCreateUser("王大宸");
        studentInfo.setCreateUserId("1");
        studentInfo.setUpdateTime(LocalDateTime.now());
        studentInfo.setUpdateUser("王大宸");
        studentInfo.setUpdateUserId("1");

        studentInfoMapper.saveStudentInfo(studentInfo);
        return StudentInfoConvert.toJavaObjectVo(studentInfo);
    }

    /***
     * 根据ID查询
     *
     * @author 王大宸
     * @date 2023/8/13 16:36
     * @param id id
     * @return com.github.itdachen.sdk.vo.StudentInfoVO
     */
    @Override
    public StudentInfoVO getStudentInfoById(String id) throws Exception {
        return studentInfoMapper.getStudentInfoById(id);
    }

    /***
     * 更新学生信息
     *
     * @author 王大宸
     * @date 2023/8/13 16:39
     * @param studentInfoDTO studentInfoDTO
     * @return com.github.itdachen.sdk.vo.StudentInfoVO
     */
    @Override
    @Transactional(rollbackFor = Exception.class)
    public StudentInfoVO updateStudentInfo(StudentInfoDTO studentInfoDTO) throws Exception {
        StudentInfo studentInfo = StudentInfoConvert.toJavaObject(studentInfoDTO);

        studentInfo.setUpdateTime(LocalDateTime.now());
        studentInfo.setUpdateUser("王大宸");
        studentInfo.setUpdateUserId("1");
        studentInfoMapper.updateStudentInfo(studentInfo);

        return StudentInfoConvert.toJavaObjectVo(studentInfo);
    }

    /***
     * 删除学生信息
     *
     * @author 王大宸
     * @date 2023/8/13 16:37
     * @param id id
     * @return void
     */
    @Override
    @Transactional(rollbackFor = Exception.class)
    public void deleteStudentInfoById(String id) throws Exception {
        studentInfoMapper.deleteStudentInfoById(id);
    }


}
