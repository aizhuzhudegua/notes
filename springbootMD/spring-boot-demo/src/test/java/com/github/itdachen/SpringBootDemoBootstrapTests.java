package com.github.itdachen;

import com.github.itdachen.mapper.IStudentInfoMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 18:28
 * Created with IntelliJ IDEA.
 */
@SpringBootTest
public class SpringBootDemoBootstrapTests {

    @Test
    public void content() {
    }

//    @Autowired
    @Resource
    private IStudentInfoMapper studentInfoMapper;

    @Test
    public void contentStudentInfo() {
        Integer count = studentInfoMapper.findCount();
        System.out.println("当前学生数量为: " + count);
    }


}
