# 一 环境准备

## 1 配置maven

-  maven地址：git clone -b maven https://github.com/aizhuzhudegua/springboot-.git

- 配置文件地址——D:\maven\apache-maven-3.9.2\conf设置settings.xml
- 配置阿里云镜像

```xml
<mirrors>
    <!-- 定义阿里云 Maven 镜像地址 -->
    <mirror>
    <id>aliyunmaven</id>
    <mirrorOf>*</mirrorOf>
    <name>aliyun maven public</name>
    <url>https://maven.aliyun.com/repository/public</url>
    </mirror>
</mirrors>

<!-- 阿里云的Spring仓库-->
<profiles>
    <profile>
        <id>aliyunSpring</id>
        <repositories>
            <repository>
                <id>spring</id>
                <url>https://maven.aliyun.com/repository/spring</url>
                <releases>
               		<enabled>true</enabled>
                </releases>
                <snapshots>
                	<enabled>true</enabled>
                </snapshots>
            </repository>

            <repository>
                <id>spring-plugin</id>
                <url>https://maven.aliyun.com/repository/spring-plugin</url>
                <releases>
                	<enabled>true</enabled>
                </releases>
                <snapshots>
                	<enabled>true</enabled>
                </snapshots>
            </repository>
        </repositories>
    </profile>
</profiles>

<!-- 手动激活profiles的列表，按照profile被应用的顺序定义activeProfile。 -->
<!-- 该元素包含了一组activeProfile元素，每个activeProfile都含有一个profile id。 -->
<!-- 任何在activeProfile中定义的profile id，不论环境设置如何，其对应的 profile都会被激活。 -->
<!-- 如果没有匹配的profile，则什么都不会发生。 -->
<!-- 如果运行过程中找不到这样一个profile，Maven则会像往常一样运行。 -->
<activeProfiles>
	<activeProfile>aliyunSpring</activeProfile>
</activeProfiles>
```

- 配置本地仓库（存储下载的依赖）

```
<!-- 定义本地 Maven 本地仓库地址 -->
<localRepository>C:\java\mvn-repository</localRepository>
```

- 完整的xml文件

```xml
<?xml version="1.0" encoding="UTF-8"?>
<settings xmlns="http://maven.apache.org/SETTINGS/1.0.0"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://maven.apache.org/SETTINGS/1.0.0 http://maven.apache.org/xsd/settings-1.0.0.xsd">
    <!-- 定义本地 Maven 本地仓库地址 -->
    <localRepository>C:\java\mvn-repository</localRepository>

    <mirrors>
        <!-- 定义阿里云 Maven 镜像地址 -->
        <mirror>
            <id>aliyunmaven</id>
            <mirrorOf>*</mirrorOf>
            <name>aliyun maven public</name>
            <url>https://maven.aliyun.com/repository/public</url>
        </mirror>
    </mirrors>

    <!-- 阿里云的Spring仓库-->
    <profiles>
        <profile>
            <id>aliyunSpring</id>
            <repositories>
                <repository>
                    <id>spring</id>
                    <url>https://maven.aliyun.com/repository/spring</url>
                    <releases>
                        <enabled>true</enabled>
                    </releases>
                    <snapshots>
                        <enabled>true</enabled>
                    </snapshots>
                </repository>

                <repository>
                    <id>spring-plugin</id>
                    <url>https://maven.aliyun.com/repository/spring-plugin</url>
                    <releases>
                        <enabled>true</enabled>
                    </releases>
                    <snapshots>
                        <enabled>true</enabled>
                    </snapshots>
                </repository>
            </repositories>
        </profile>
    </profiles>

    <!-- 手动激活profiles的列表，按照profile被应用的顺序定义activeProfile。 -->
    <!-- 该元素包含了一组activeProfile元素，每个activeProfile都含有一个profile id。 -->
    <!-- 任何在activeProfile中定义的profile id，不论环境设置如何，其对应的 profile都会被激活。 -->
    <!-- 如果没有匹配的profile，则什么都不会发生。 -->
    <!-- 如果运行过程中找不到这样一个profile，Maven则会像往常一样运行。 -->
    <activeProfiles>
        <activeProfile>aliyunSpring</activeProfile>
    </activeProfiles>
</settings>
```

## 2 IDEA设置本地maven

- File>Setting

  ![maven](images\maven.png)

  

# 二 新建项目

## 1 以maven的方式创建

![创建项目](images\创建项目.png)

- 创建完成后的项目结构（空项目）

  ![项目目录](images\项目目录.png)

## 2 使用MybatisX插件生成代码

FIle>Setting>Plugins下载插件

![mybatisx](images\mybatisx.png)

- 选择mysql数据库

  ![mysql](images\mysql.png)

- 输入已有的数据库信息

  ![db](images\db.png)

- 在数据库列表里选择要连接的表，生成代码

  ![gen](images\gen.png)

- 按个人习惯更改enity目录名称

  ![gen1](images\gen1.png)

- 点击下一步，如下设置

  ![gen3](images\gen3.png)

- 生成后的目录

  ![gen4](images\gen4.png)

## 3 修改pom文件，配置依赖

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>com.github.itdachen</groupId>
    <artifactId>spring-boot-demo</artifactId>
    <version>1.0-SNAPSHOT</version>



    <!--导入springboot父工程-规定写法-->
    <parent>
        <artifactId>spring-boot-starter-parent</artifactId>
        <groupId>org.springframework.boot</groupId>
        <version>2.5.3</version>
    </parent>


    <dependencies>

        <dependency>
            <groupId>com.baomidou</groupId>
            <artifactId>mybatis-plus-boot-starter</artifactId>
            <version>3.4.3</version>
        </dependency>
     
        <!--引入web starter-->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <!--引入mybatis starter, 如果小伙伴看不到 版本，自己手写2.2.2-->
        <dependency>
            <groupId>org.mybatis.spring.boot</groupId>
            <artifactId>mybatis-spring-boot-starter</artifactId>
            <version>2.2.2</version>
        </dependency>

        <!--引入mysql驱动: 这里使用版本仲裁 8.0.26-->
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
        </dependency>

        <!--引入配置处理器 -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-configuration-processor</artifactId>
        </dependency>

        <!--引入lombok-->
        <dependency>
            <groupId>org.projectlombok</groupId>
            <artifactId>lombok</artifactId>
        </dependency>

        <!--引入test starter-->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-test</artifactId>
        </dependency>

        <!--引入druid依赖-->
        <dependency>
            <groupId>com.alibaba</groupId>
            <artifactId>druid</artifactId>
            <version>1.1.17</version>
        </dependency>
    </dependencies>

</project>

```



- 修改完成后点击刷新，等待依赖下载完成

  ![depends](images\depends.png)

## 4 向前端提供访问接口

- 在generator下新建包controller，在包下创建xxxController.class

  ![image-20231116143250984](images\image-20231116143250984.png)

![image-20231116143435479](images\image-20231116143435479.png)

- 写一个Controller供前端请求

  这里请求了Service层的一个接口（稍后会提到），是根据id查Buildings表，返回一个Buildings实体，**注意这里的id就是实体类中注解了@TableId(value = "id")的字段**。

  设置了GetMapping并且携带了一个参数，规定该接口只能通过GET请求，请求示例如下：

  **GET**http://localhost:8080//building/1

  下文会专门用接口测试工具测试

  ```java
  package generator.controller;
  
  import generator.entity.Buildings;
  import generator.service.BuildingsService;
  import org.springframework.beans.factory.annotation.Autowired;
  import org.springframework.stereotype.Controller;
  import org.springframework.web.bind.annotation.GetMapping;
  import org.springframework.web.bind.annotation.PathVariable;
  import org.springframework.web.bind.annotation.RequestMapping;
  import org.springframework.web.bind.annotation.ResponseBody;
  
  @Controller
  @RequestMapping("/building")
  public class BuildingController {
  
      @Autowired
      BuildingsService buildingsService;
  
      @GetMapping("/{id}")
      @ResponseBody
      public Buildings helloSpringBoot(@PathVariable("id") Integer id) {
          return buildingsService.getById(id);
      }
  }
  ```

  

- 在service层实现getById

  ![image-20231116202234700](images\image-20231116202234700.png)

  BuildingsService接口的内容：

  ```java
  package generator.service;
  
  import generator.entity.Buildings;
  import com.baomidou.mybatisplus.extension.service.IService;
  
  /**
  * @author 王周凯
  * @description 针对表【buildings】的数据库操作Service
  * @createDate 2023-11-16 14:19:33
  */
  public interface BuildingsService extends IService<Buildings> {
  
      Buildings getById(Integer id);
  }
  
  ```

  BuildingsServiceImpl的内容：

  ```java
  package generator.service.impl;
  
  import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
  import generator.entity.Buildings;
  import generator.service.BuildingsService;
  import generator.mapper.BuildingsMapper;
  import org.springframework.beans.factory.annotation.Autowired;
  import org.springframework.stereotype.Service;
  
  /**
  * @author 王周凯
  * @description 针对表【buildings】的数据库操作Service实现
  * @createDate 2023-11-16 14:19:33
  */
  @Service
  public class BuildingsServiceImpl extends ServiceImpl<BuildingsMapper, Buildings>
      implements BuildingsService{
      @Autowired
      BuildingsMapper buildingsMapper;
      @Override
      public Buildings getById(Integer id) {
          //调用service层接口，根据id返回Buildings实体
          return buildingsMapper.selectById(id);
      }
  }
  ```

  这个接口实现中调用了mapper层的selectById，事实上他是MybatisPlus实现的，可以根据id查数据库，mapper层并不需要写东西

- 看下mapper（BuildingsMapper）

  可以看到service层的BuildingsMapper是继承了BaseMapper，他就是MybatisPlus提供给我们的一个实现了许多功能的类，诸如增删改查以及分页查询

  ```java
  package generator.mapper;
  
  import generator.entity.Buildings;
  import com.baomidou.mybatisplus.core.mapper.BaseMapper;
  import org.apache.ibatis.annotations.Mapper;
  
  /**
  * @author 王周凯
  * @description 针对表【buildings】的数据库操作Mapper
  * @createDate 2023-11-16 14:19:33
  * @Entity generator.entity.Buildings
  */
  @Mapper
  public interface BuildingsMapper extends BaseMapper<Buildings> {
  
  }
  ```

  

- 最后写一个启动类SpringBootDemoBootstrap

  ```java
  package generator;
  
  import org.springframework.boot.SpringApplication;
  import org.springframework.boot.autoconfigure.SpringBootApplication;
  
  @SpringBootApplication
  public class SpringBootDemoBootstrap {
  
      public static void main(String[] args) {
          SpringApplication.run(SpringBootDemoBootstrap.class);
      }
  
  }
  ```

- 配置项application.yml

  ```
  server:
    port: 8080
  
  spring:
    application:
      name: spring-boot-demo
  
    datasource:
      driver-class-name: com.mysql.cj.jdbc.Driver
      url: jdbc:mysql://localhost:3306/3d-app?characterEncoding=utf-8&useSSL=false&serverTimezone=GMT
      username: root
      password:
  
  ```

  注意修改：

  ![image-20231116203424484](images\image-20231116203424484.png)

- 最终项目目录

  ![image-20231116203528843](images\image-20231116203528843.png)

# 三 测试接口

## 1 启动测试类

![image-20231116203559296](images\image-20231116203559296.png)

## 2 使用ApiFox工具测试接口

![image-20231117094012581](images\image-20231117094012581.png)

# 四 写需求

通过上面的步骤实现了根据id查building的需求，类似的步骤，写一个返回根据id返回设备信息的接口

## 1 controller接口

```java
package generator.controller;

import generator.entity.Device;
import generator.service.DeviceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/device")
public class DeviceController {

    @Autowired
    DeviceService deviceService;

    @GetMapping("/{id}")
    @ResponseBody
    public Device GetById(@PathVariable("id") Integer id) {
        return deviceService.getById(id);
    }
    
}
```

## 2 接口测试

![image-20231117100347707](images\image-20231117100347707.png)



## 5 对接前端