package com.github.itdachen.controller;

import com.github.itdachen.common.response.ServerResponse;
import com.github.itdachen.common.response.TableData;
import com.github.itdachen.sdk.dto.StudentInfoDTO;
import com.github.itdachen.sdk.query.StudentInfoQuery;
import com.github.itdachen.sdk.vo.StudentInfoVO;
import com.github.itdachen.service.IStudentInfoService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 21:50
 * Created with IntelliJ IDEA.
 */
@Controller
@RequestMapping("/student/info")
public class StudentInfoController {

    public final IStudentInfoService studentInfoService;

    public StudentInfoController(IStudentInfoService studentInfoService) {
        this.studentInfoService = studentInfoService;
    }

    /***
     * 跳转到管理页面
     *
     * @author 王大宸
     * @date 2023/8/12 22:20
     * @return java.lang.String
     */
    @GetMapping("/index")
    public String index() {
        return "student/index";
    }

    /***
     * 分页查询
     *
     * @author 王大宸
     * @date 2023/8/12 22:27
     * @param query query
     * @return com.github.itdachen.common.response.ServerResponse<com.github.itdachen.common.response.TableData < com.github.itdachen.sdk.vo.StudentInfoVO>>
     */
    @GetMapping("/page")
    @ResponseBody
    public ServerResponse<TableData<StudentInfoVO>> page(StudentInfoQuery query) throws Exception {
        return ServerResponse.okData(studentInfoService.findStudentInfoPage(query));
    }

    /***
     * 跳转到新增页面
     *
     * @author 王大宸
     * @date 2023/8/12 22:20
     * @return java.lang.String
     */
    @GetMapping("/add")
    public String add() {
        return "student/add";
    }

    /***
     * 新增学生信息
     *
     * @author 王大宸
     * @date 2023/8/12 23:30
     * @param studentInfoDTO studentInfoDTO
     * @return com.github.itdachen.common.response.ServerResponse<com.github.itdachen.sdk.vo.StudentInfoVO>
     */
    @PostMapping("")
    @ResponseBody
    public ServerResponse<StudentInfoVO> saveStudentInfo(@RequestBody StudentInfoDTO studentInfoDTO) throws Exception {
        return ServerResponse.okData(studentInfoService.saveStudentInfo(studentInfoDTO));
    }

    /***
     * 跳转到编辑页面
     *
     * @author 王大宸
     * @date 2023/8/13 16:44
     * @param id id
     * @param modelMap modelMap
     * @return java.lang.String
     */
    @GetMapping("/edit/{id}")
    public String edit(@PathVariable("id") String id, ModelMap modelMap) throws Exception {
        modelMap.put("studentInfo", studentInfoService.getStudentInfoById(id));
        return "student/edit";
    }

    /***
     * 更新数据接口
     *
     * @author 王大宸
     * @date 2023/8/13 16:45
     * @param studentInfoDTO studentInfoDTO
     * @return com.github.itdachen.common.response.ServerResponse<com.github.itdachen.sdk.vo.StudentInfoVO>
     */
    @PutMapping("/{id}")
    @ResponseBody
    public ServerResponse<StudentInfoVO> updateStudentInfo(@RequestBody StudentInfoDTO studentInfoDTO) throws Exception {
        return ServerResponse.okData(studentInfoService.updateStudentInfo(studentInfoDTO));
    }

    /***
     * 跳转到查看页面
     *
     * @author 王大宸
     * @date 2023/8/13 16:45
     * @param id id
     * @param modelMap modelMap
     * @return java.lang.String
     */
    @GetMapping(value = "/view/{id}")
    public String view(@PathVariable("id") String id, ModelMap modelMap) throws Exception {
        modelMap.put("studentInfo", studentInfoService.getStudentInfoById(id));
        return "student/view";
    }

    /***
     * 根据 ID 删除学生信息
     *
     * @author 王大宸
     * @date 2023/8/13 17:10
     * @param id id
     * @return com.github.itdachen.common.response.ServerResponse<com.github.itdachen.sdk.vo.StudentInfoVO>
     */
    @DeleteMapping("/{id}")
    @ResponseBody
    public ServerResponse<StudentInfoVO> deleteStudentInfo(@PathVariable("id") String id) throws Exception {
        studentInfoService.deleteStudentInfoById(id);
        return ServerResponse.ok();
    }

}
