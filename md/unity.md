[TOC]

# unity的架构

![image-20231201145508727](C:\Users\王周凯\AppData\Roaming\Typora\typora-user-images\image-20231201145508727.png)



# C#的反射机制

编译器会为每个类生成**Type**的描述

![image-20241007094420234](images/image-20241007094420234.png)

例如：

![image-20241007094559968](images/image-20241007094559968.png)

![image-20241007094559968](images/image-20241007094559968.png)

![image-20241007100136517](images/image-20241007100136517.png)

代码实现：

![image-20241007100156637](images/image-20241007100156637.png)

![image-20241007100136517](images/image-20241007100136517.png)

![image-20241007100245538](images/image-20241007100245538.png)

**在unity中脚本的名字必须和类名相同，这是由于创建脚本实例的时候需要读取文件名/类名来创建类**

# 常用操作

- Alt+RMB 缩放
- Alt+RML 旋转
- 中键 平移
- F 置于视图中心
- backspace 回退
- gameobject中选中camera然后 algin with view，可使scene和game视角一致
- edit中 lockViewToSelected
- ctrl+移动 增量移动
- v 顶点对齐
- ![image-20241017203052864](images/image-20241017203052864.png)

# 常用设置

- 在increment snapping 设置旋转角度

![image-20241017151406130](images/image-20241017151406130.png)

# 约定

- 一格约定为1m

# 坐标

左手系，与opengl的z轴相反

## 局部坐标（local）（Space.Self）

每个物体包括相机都有：x = right，y = up，z = forword 

![image-20241017160822955](images/image-20241017160822955.png)

![image-20241007152922933](images/image-20241007152922933.png)

## global 全局/世界坐标

## 屏幕坐标

![image-20241005222439263](images/image-20241005222439263.png)

#### 获取屏幕尺寸

![image-20241005222554780](images/image-20241005222554780.png)

#### 获取一个物体在屏幕上的位置

Z值是离摄像机的距离

![image-20241005222811702](images/image-20241005222811702.png)

![image-20241005222936667](images/image-20241005222936667.png)

#### 判断一个物体是否出了屏幕

![image-20241005223143062](images/image-20241005223143062.png)

# 颜色空间

gamma和linear具有不同的表现

<img src="images/image-20241025221849904.png" alt="image-20241025221849904" style="zoom:50%;" />

# 空物体

组织和管理其他节点

# 层级关系

Unity的父子节点关系是由**Transform**组件来维持的

gameObject可以忽略

## 获取子节点数量

```c#
int childCount = this.transform.childCount;
```

## 获取子节点

![image-20241006161908386](images/image-20241006161908386.png)

![image-20241006162315551](images/image-20241006162315551.png)

![image-20241006162623281](images/image-20241006162623281.png)

## 获取父节点

![image-20241006162016350](images/image-20241006162016350.png)

## 设置父级

![image-20241006162830080](images/image-20241006162830080.png)

## 从根开始查找

![image-20241006163023017](images/image-20241006163023017.png)

# 外部模型

## FBX：unity标准格式

修改材质的方式

1、材质重映射

![image-20241005151542815](images/image-20241005151542815.png)

2、使用外部材质

![image-20241005151623906](images/image-20241005151623906.png)

3、分解重组

# 组件

## 1、Audio souce

属性

- Audio clip 音频源
- 自动播放

![image-20241005220450442](images/image-20241005220450442.png)

## 2、transform（基础组件，无法删除）

Inspector显示的transform是**相对坐标**

## 3、脚本组件

- 文件名就是类名
- 反射机制实现的

# 运行时的参数如何保留

![image-20241005215635808](images/image-20241005215635808.png)

![image-20241005215712336](images/image-20241005215712336.png)

# 脚本

## 属性

![image-20241025091008498](images/image-20241025091008498.png)

## 注解编程

```c#
[Tooltip("y轴向的角速度")]
public float rotateSpeed = 5.0f; // 30°/s
```

![image-20241005204733703](images/image-20241005204733703.png)

### 常用注解

https://blog.csdn.net/mr_five55/article/details/134721810

## 消息函数

Awake/Start只执行一次

![image-20241005202819514](images/image-20241005202819514.png)

## 脚本执行顺序

每一阶段的执行顺序是不确定的，但是阶段是有顺序的

![image-20241005203107032](images/image-20241005203107032.png)

优先级的设定——值越小优先级越高，默认全都是0

![image-20241005203454081](images/image-20241005203454081.png)

## 脚本参数

public修饰

## 参数的赋值顺序

1、public float rotateSpeed = 5.0f; 

2、inspector

![image-20241005205258733](images/image-20241005205258733.png)

3、Awake

4、Start

## 值类型

![image-20241005205433876](images/image-20241005205433876.png)

![image-20241005205725324](images/image-20241005205725324.png)

### 引用类型

![image-20241005205942781](images/image-20241005205942781.png)

## 常用函数和属性

- ### forward（z）朝向函数

  this.transform.LookAt(targetPos);  

  this.transform.LookAt(obj.transform);

- ### 获取scene 中的gameobject

  GameObject.Find("TagName");

  GameObject.Find("a/b/c");

- ### 向量模

  distance.magnitude

- ### 单位向量

  distance.normalized

- ### 旋转

  transform.eulerAngles = new Vector3(x,y,z) // 输入度

  transform.localEulerAngles  = new Vector3(x,y,z) // 输入度

- ### 限制帧率

  Application.targetFrameRate = 60; // 16.7ms

## 获取transform的坐标

```c#
void Start()
{
    GameObject obj = this.gameObject;
    Transform trans = obj.transform;
    // 全局
    Vector3 postion = trans.position;
    // 局部
    Vector3 localPostion = trans.localPosition;
    Debug.Log(postion.ToString("F3"));
    Debug.Log(localPostion.ToString("F3"));
    Debug.Log(obj.name); 
}
```

![image-20241005152819127](images/image-20241005152819127.png)

## 帧更新

帧更新时间是不固定的

```c#
void Update()
{
    // Debug.Log("现在的时间是: " + Time.time);
    Debug.Log("帧生成时间差: " + Time.deltaTime);
}
```

锁帧率

```c#
void Start()
{
    Application.targetFrameRate = 60; // 16.7ms
}
```

## 利用transform组件移动

并不是匀速的，因为帧生成不稳定

```c#
void Update()
{
    Vector3 pos = this.transform.localPosition;
    pos.x += 0.01f;
    this.transform.localPosition = pos;
}
```

匀速的运动

```c#
void Update()
{
    // 3m/s
    float speed = 3.0f;
    float distance = Time.deltaTime* speed;
    Vector3 pos = this.transform.localPosition;
    pos.x += distance;
    this.transform.localPosition = pos;
}
```

等价的 Translate(dx,dy,dz,space) 

- Space.World
- Space.Self // 默认

```c#
void Update()
{
    // 3m/s
    float speed = 3.0f;
    float distance = Time.deltaTime* speed;
    // 向右移动
    this.transform.Translate(distance, 0, 0);
}
```

## 射线检测实现Moba移动

目前存在射线击中自己时的bug

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Demo : MonoBehaviour
{
    // Start is called before the first frame update
    private Camera mainCamera;
    void Start()
    {
        // TODO 获取相机
        mainCamera = Camera.main.GetComponent<Camera>();
        Application.targetFrameRate = 60; // 16.7ms
    }

    // Update is called once per frame
    private Vector3 targetPos;
    void Update()
    {
        if(Input.GetMouseButton(0))
        {
            Ray ray = mainCamera.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            if (Physics.Raycast(ray, out hit))
            {
                targetPos = hit.point;
                // 看向目标
                this.transform.LookAt(targetPos);
            }
        }
        // 停止条件
        float distance = (targetPos - this.transform.position).magnitude;
        if (distance > 0.5)
        {
            // 移动
            // 3m/s
            float speed = 3.0f;
            float deltaDistance = Time.deltaTime * speed;
            this.transform.Translate(0, 0, deltaDistance, Space.Self);
        }
        
    }
}

```

## 旋转

读取 .eulerAngles 属性时，Unity 会将四元数的旋转内部表示形式转换为 Euler 角。因为使用欧拉角表示任何给定旋转的方法不止一种，所以读回的值可能与分配的值完全不同，**在实现递增时尽量避免使用Rotate或者读取eulerAngles**，Rotate内部实现读取了 .eulerAngles

unity inspector上的rotation是一个**四元数**，不方便代码使用，常用的是**欧拉角**

<img src="images/image-20241007170628254.png" alt="image-20241007170628254" style="zoom: 33%;" />

```c#
void Update()
{
    float speed = 30.0f; // 30°/s
    float deltaAngle = speed * Time.deltaTime;
    Vector3 angle = this.transform.localEulerAngles;
    angle.y += deltaAngle;
    this.transform.localEulerAngles = angle;
}
```

使用Rotate函数

```c#
void Update()
{
    float speed = 30.0f; // 30°/s
    float deltaAngle = speed * Time.deltaTime;
    this.transform.Rotate(0, deltaAngle, 0, Space.Self);
}
```

火控

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireLogic : MonoBehaviour
{
    public float bulletSpeed;
    public float bulletLifetime;
    public float shotSpeed; // 射速
    public float rotateSpeed = 1.0f;

    public GameObject bulletPrefab;
    public Transform bulletFolder;
    public Transform firePoint;
    public Transform cannon;

    private bool isFire = false;

    public Vector3 currentEurlerAngles;
    // Start is called before the first frame update
    void Start()
    {
        InvokeRepeating("TestFire", 0.0f, shotSpeed);
    }
    
    // Update is called once per frame
    void Update()
    {
        isFire = Input.GetMouseButton(0);
        if(Input.GetKey(KeyCode.W))
        {
            currentEurlerAngles.x -= rotateSpeed * Time.deltaTime;
        }
        else if (Input.GetKey(KeyCode.S))
        {
            currentEurlerAngles.x += rotateSpeed * Time.deltaTime;
        }
        else if (Input.GetKey(KeyCode.A))
        {
            currentEurlerAngles.y -= rotateSpeed * Time.deltaTime;
        }
        else if (Input.GetKey(KeyCode.D))
        {
            currentEurlerAngles.y += rotateSpeed * Time.deltaTime;
        }
        currentEurlerAngles.x = Mathf.Clamp(currentEurlerAngles.x, -60.0f, 60.0f);
        currentEurlerAngles.y = Mathf.Clamp(currentEurlerAngles.y, -60.0f, 60.0f);
        cannon.localEulerAngles = currentEurlerAngles;
    }

    void TestFire()
    {
        if(isFire)
        {
            GameObject node = Object.Instantiate(bulletPrefab, bulletFolder);
            node.transform.position = firePoint.position;
            node.transform.eulerAngles = cannon.eulerAngles;
            BulletLogic script = node.GetComponent<BulletLogic>();
            script.speed = bulletSpeed;
            script.maxDistance = script.speed * bulletLifetime; // 5m，10s后消失
        }
    }
}
```



## 自转和公转

![image-20241005201015989](images/image-20241005201015989.png)

a1和地球都位于原点

1、地球自转

```c#
void Update()
{
    float speed = 30.0f; // 30°/s
    float deltaAngle = speed * Time.deltaTime;
    this.transform.Rotate(0, deltaAngle, 0, Space.Self);
}
```

2、卫星公转

```c#
void Update()
{
    float speed = 60.0f; // 30°/s
    float deltaAngle = speed * Time.deltaTime;
    Transform parent = this.transform.parent;
    parent.Rotate(0, deltaAngle, 0, Space.Self);
}
```

## 游戏输入

### 鼠标输入

![image-20241005220914485](images/image-20241005220914485.png)

![image-20241005221327768](images/image-20241005221327768.png)

#### 事件探测和状态探测

![image-20241005221708290](images/image-20241005221708290.png)

#### 获取鼠标按下位置

```c#
if ( Input.GetMouseButtonDown( 0 ))
{
    Debug.Log(Input.mousePosition);
}
```

### 键盘输入

![image-20241006112600654](images/image-20241006112600654.png)

![image-20241006112730574](images/image-20241006112730574.png)

对于每帧都需要判断的逻辑使用**状态**

![image-20241006113320523](images/image-20241006113320523.png)

## 组件的调用

### 音频组件

```c#
void PlayMusic()
{
    AudioSource audio = this.GetComponent<AudioSource>();
    if(audio.isPlaying)
    {
        audio.Stop();
    }
    else
    {
        audio.Play();
    }
}
```

### 调用其他GameObject的音频组件

```c#
private void Awake()
    {
        Application.targetFrameRate = 60;
        GameObject bgMusic = GameObject.Find("背景音乐");
        bgMusic.GetComponent<AudioSource>().Play(); 
    }
```

unity对音频组件的调用做了优化

1、定义AudioSouce成员而不是GameObject

```c#
public AudioSource bgm;
private void Awake()
{
    Application.targetFrameRate = 60;
    bgm.Play(); 
}
```

2、把带有AudioSource的GameObject拖入能够自动识别

![image-20241006115948393](images/image-20241006115948393.png)

### 脚本组件的引用

```c#
Planet planet = earth.GetComponent<Planet>();
planet.rotateSpeed = 30;
```

常用

```c#
public Planet bgm;
```

## 组件通信

![image-20241006153645170](images/image-20241006153645170.png)

## 物体的显示和隐藏

![image-20241006163212707](images/image-20241006163212707.png)



## 音乐资源的引用——音效

调用**AudioSource**组件播放不同音频资源

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioTest : MonoBehaviour
{
    public AudioClip audioSuccess;
    public AudioClip audioFail;
    // Start is called before the first frame update
    void Start()
    {
        
    }
    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.A))
        {
            AudioSource audioSource = this.GetComponent<AudioSource>();
            audioSource.PlayOneShot(audioSuccess);
        }
        if (Input.GetKeyDown(KeyCode.D))
        {
            AudioSource audioSource = this.GetComponent<AudioSource>();
            audioSource.PlayOneShot(audioFail);
        }

    }
}
```

## 音乐资源的引用——音乐盒

```c#
void NextSong()
{
    int index = Random.Range(0, songs.Length);
    AudioSource audioSource = this.GetComponent<AudioSource>();
    audioSource.clip = this.songs[index];
    audioSource.Play();
}
```

## 材质资源的引用——三色球

```c#
void ChangeColor()
{
    cur++;
    if(cur >= this.colors.Length)
    {
        cur = 0;
    }
    Material selected = this.colors[cur];
    this.GetComponent<MeshRenderer>().material = selected;
}
```

## 定时器

- 反射机制实现的
- **事件函数的执行是一个大循环，任何的事件调度都塞进 *脚本生命周期大循环* ，在合适的时间发生调度**
- 每次InvokeRepeating都会增加新的调度

![image-20241007090730929](images/image-20241007090730929.png)

![image-20241007103044904](images/image-20241007103044904.png)

### 弹跳的小球

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InvokeTest : MonoBehaviour
{
    public float speed = 1.5f;
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log(Time.time);
        this.InvokeRepeating("doSomething", 2 , 2);
    }

    // Update is called once per frame
    void Update()
    {
        this.transform.Translate(0, speed * Time.deltaTime, 0, Space.Self);
    }
    private void doSomething()
    {
        Debug.Log("do something " + Time.time);
        speed = -speed;
    }
}
```

### 红绿灯

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class hongludeng : MonoBehaviour
{
    public Material[] colors;
    private int cur;
    // Start is called before the first frame update
    void Start()
    {
        ChangeColor();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void ChangeColor()
    {
        Material color = colors[cur];
        MeshRenderer meshRenderer = GetComponent<MeshRenderer>();
        meshRenderer.material = color;
        if(cur == 0)
        {
            Invoke("ChangeColor", 4);
        }
        else if(cur == 1)
        {
            Invoke("ChangeColor", 4);
        }
        else if (cur == 2)
        {
            Invoke("ChangeColor", 1);
        }
        cur++;
        if (cur >= colors.Length)
        {
            cur = 0;
        }
    }
}
```

## 加速减速

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class jiasujiansu : MonoBehaviour
{
    float a = 100; // 加速度
    float speed = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // 鼠标按下时加速
        if(Input.GetMouseButton(0))
        {
            // 计算速度的增加
            speed += Time.deltaTime * a;
        }
        // 鼠标松开时减速
        else
        {
            speed += Time.deltaTime * -50;
        }
        if (speed < 0) speed = 0;
        transform.Rotate(0, Time.deltaTime*speed, 0, Space.Self);
    }

}

```

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class jiasujiansu : MonoBehaviour
{
    public float maxSpeed = 720;
    float speed = 0;
    bool isAcc = false;
    // Start is called before the first frame update
    void Start()
    {
        InvokeRepeating("AdjustSpeed", 0.1f, 0.1f);
    }

    // Update is called once per frame
    void Update()
    {
        // 切换开关
        if(Input.GetMouseButton(0))
        {
            isAcc = !isAcc;
        }
        
        if(speed > 0)
        {
            transform.Rotate(0, Time.deltaTime * speed, 0, Space.Self);
        }
    }

    void AdjustSpeed()
    {
        if(isAcc)
        {
            if (speed < maxSpeed)
                speed += 10;
        }
        else
        {
            if (speed > 0)
                speed -= 10;
        }
    }
}

```

## 向量

![image-20241007153636023](images/image-20241007153636023.png)

# 预制体

prefab发生修改，实例也会同步的发生修改

## 创建

![image-20241007155255207](images/image-20241007155255207.png)

## 导出

![image-20241007155822683](images/image-20241007155822683.png)

## 转为普通物体

![image-20241007160133844](images/image-20241007160133844.png)

## 编辑

![image-20241007160405005](images/image-20241007160405005.png)

![image-20241007160418227](images/image-20241007160418227.png)

![image-20241007160801816](images/image-20241007160801816.png)

![image-20241007160711943](images/image-20241007160711943.png)

# 动态创建实例

![image-20241007161449629](images/image-20241007161449629.png)

子弹

```c#
void TestFire()
{
    GameObject node = Object.Instantiate(bulletPrefab, bulletFolder);
    node.transform.position = firePoint.position;
    node.transform.eulerAngles = cannon.eulerAngles;
    node.GetComponent<BulletLogic>().speed = 1;
}
```

# 销毁实例

![image-20241007172442571](images/image-20241007172442571.png)

# 物理系统

## 刚体

## 碰撞体

![image-20241008161734893](images/image-20241008161734893.png)

![image-20241008162408960](images/image-20241008162408960.png)

# 天空盒

## 天空盒材质

![image-20241017201657372](images/image-20241017201657372.png)

![image-20241017201735116](images/image-20241017201735116.png)

![image-20241008164628831](images/image-20241008164628831.png)

## 天空盒贴图

天空盒贴图设置为clamp确保无缝

![image-20241017202627993](images/image-20241017202627993.png)

# 光照

## 环境光设置

![image-20241017145815156](images/image-20241017145815156.png)

# 粒子系统

## 基础参数

![image-20241010123343591](images/image-20241010123343591.png)

![image-20241009203847458](images/image-20241009203847458.png)

![image-20241009205015980](images/image-20241009205015980.png)

![image-20241009205147897](images/image-20241009205147897.png)

## 粒子发生器

![image-20241009205735254](images/image-20241009205735254.png)

## 广告牌

![image-20241009210045110](images/image-20241009210045110.png)

## 粒子贴图

![image-20241009210155518](images/image-20241009210155518.png)

![image-20241009210625572](images/image-20241009210625572.png)

### Additve

![image-20241009212815108](images/image-20241009212815108.png)

黑色叠加

![image-20241009213112066](images/image-20241009213112066.png)

### Multiply

Start Color和贴图相乘

### 两个效果叠加

![image-20241009213802142](images/image-20241009213802142.png)

![image-20241009214218073](images/image-20241009214218073.png)

## 黑底白图

![image-20241010121739237](images/image-20241010121739237.png)

![image-20241010121833183](images/image-20241010121833183.png)

## 透明底图

![image-20241010122125554](images/image-20241010122125554.png)

![image-20241010122303499](images/image-20241010122303499.png)

![image-20241010122431823](images/image-20241010122431823.png)

![image-20241010122620095](images/image-20241010122620095.png)

## 区间随机值

![image-20241010123130194](images/image-20241010123130194.png) 

## 周期与时长

![image-20241010123440130](images/image-20241010123440130.png)

## 模拟空间

![image-20241010123903810](images/image-20241010123903810.png)

world模式下已经发射的粒子不会随着粒子发射系统移动

![image-20241010124012491](images/image-20241010124012491.png)

## 匀速发射

![image-20241010124149200](images/image-20241010124149200.png)

![image-20241010124243430](images/image-20241010124243430.png)

## 最大粒子数量

![image-20241010124557626](images/image-20241010124557626.png)

## 爆发发射

![image-20241010124729795](images/image-20241010124729795.png)

一般去掉looping

![image-20241010125121214](images/image-20241010125121214.png)

## 爆炸参数

![image-20241010125333286](images/image-20241010125333286.png)

## 发射器形状

![image-20241010125505003](images/image-20241010125505003.png)

## Cone

![image-20241010130125534](images/image-20241010130125534.png)

angle是单边的

## Color Over LifeTime

![image-20241011135515831](images/image-20241011135515831.png)

![image-20241011135827855](images/image-20241011135827855.png)

### 淡入淡出

![image-20241011135752283](images/image-20241011135752283.png)

## 渐变和start color的混合规则

![image-20241011140040163](images/image-20241011140040163.png)

![image-20241011140130648](images/image-20241011140130648.png)

## 大小渐变

![image-20241011150244940](images/image-20241011150244940.png)

## 速度控制

![image-20241011151807238](images/image-20241011151807238.png)

![image-20241011154245048](images/image-20241011154245048.png)

## 环绕

![image-20241011154745573](images/image-20241011154745573.png)

## 速度叠加

![image-20241011155635381](images/image-20241011155635381.png)

## 速度调节因子

![image-20241011160326699](images/image-20241011160326699.png)

![image-20241011160410739](images/image-20241011160410739.png)

## 粒子受力

![image-20241011162519805](images/image-20241011162519805.png)

![image-20241011163106439](images/image-20241011163106439.png)

### 模拟重力

![image-20241011163132594](images/image-20241011163132594.png)

### 介质阻力

![image-20241011164601550](images/image-20241011164601550.png)

![image-20241011164458837](images/image-20241011164458837.png)

### 噪声

![image-20241011164803789](images/image-20241011164803789.png)

## 粒子的旋转

![image-20241011165025285](images/image-20241011165025285.png)

![image-20241011192258608](images/image-20241011192258608.png)

![image-20241011192700555](images/image-20241011192700555.png)

### 花瓣飞舞效果

![image-20241011194522393](images/image-20241011194522393.png)

## 拉伸广告牌模式

粒子贴图左边为头部方向，粒子转向头部方向

![image-20241011195853967](images/image-20241011195853967.png)

![image-20241011200004483](images/image-20241011200004483.png)

![image-20241011200819406](images/image-20241011200819406.png)

![image-20241011201101188](images/image-20241011201101188.png)

### 火星飞溅

![image-20241011201641265](images/image-20241011201641265.png)

## 水平广告牌模式

![image-20241011205835450](images/image-20241011205835450.png)

![image-20241011205752897](images/image-20241011205752897.png)

### 旋转法门

8s发射一个粒子，一个粒子每秒转45度需要8秒转完一周

![image-20241014202939478](images/image-20241014202939478.png)

## 拖尾

![image-20241014204412821](images/image-20241014204412821.png)

![image-20241014204136007](images/image-20241014204136007.png)

![image-20241014204903816](images/image-20241014204903816.png)

### 拖尾的长度

![image-20241014205016308](images/image-20241014205016308.png)

### 拖尾的宽度

![image-20241014205207161](images/image-20241014205207161.png)

### 拖尾的颜色

![image-20241014210741195](images/image-20241014210741195.png)

![image-20241014210902159](images/image-20241014210902159.png)

### 拖尾的形状

![image-20241014205549348](images/image-20241014205549348.png)

![image-20241014205801654](images/image-20241014205801654.png)

### 烟花爆炸

![image-20241014212748013](images/image-20241014212748013.png)

## Texture Sheet Animation

![image-20241015132752153](images/image-20241015132752153.png)

![image-20241015132608883](images/image-20241015132608883.png)

![image-20241015133439973](images/image-20241015133439973.png)

![image-20241015133946508](images/image-20241015133946508.png)

### 材质的HDR可以调整亮度

![image-20241015133718083](images/image-20241015133718083.png)

### 火焰的轴心

![image-20241015133825427](images/image-20241015133825427.png)

### 烛火效果

![image-20241015134616387](images/image-20241015134616387.png)

![image-20241015134821039](images/image-20241015134821039.png)

## 粒子发光

### 携带点光源

![image-20241015135739358](images/image-20241015135739358.png)

### Lights模块

![image-20241015141817329](images/image-20241015141817329.png)

![image-20241015152402111](images/image-20241015152402111.png)

## 空粒子系统

禁用emission的粒子系统

![image-20241016111142585](images/image-20241016111142585.png)

## 二级粒子

![image-20241016115120352](images/image-20241016115120352.png)

![image-20241016114734027](images/image-20241016114734027.png)

![image-20241016115031505](images/image-20241016115031505.png)

![image-20241016115207566](images/image-20241016115207566.png)

### 注意

![image-20241016121216840](images/image-20241016121216840.png)

![image-20241016193929892](images/image-20241016193929892.png)

## 粒子的碰撞

![image-20241016202216441](images/image-20241016202216441.png)

![image-20241016203210402](images/image-20241016203210402.png)

<img src="images/image-20241016203336014.png" alt="image-20241016203336014" style="zoom:50%;" />

![image-20241016203609109](images/image-20241016203609109.png)

### 粒子碰撞事件

脚本挂在粒子上

![image-20241016211746285](images/image-20241016211746285.png) 

## 播放完毕后自毁

![image-20241016214539572](images/image-20241016214539572.png)

## 均匀分布

![image-20241016221404906](images/image-20241016221404906.png)

![image-20241016221437840](images/image-20241016221437840.png)

# 动画

![image-20241018142545596](images/image-20241018142545596.png)

## 动画曲线

![image-20241018160624961](images/image-20241018160624961.png)

![image-20241018161232477](images/image-20241018161232477.png)

## 曲线的编辑

![image-20241018162008344](images/image-20241018162008344.png)

## 动画事件

![image-20241020203325529](images/image-20241020203325529.png)

## 播放模式

![image-20241020204111364](images/image-20241020204111364.png)

# 动画状态机

![image-20241020204419700](images/image-20241020204419700.png)

## 绑定动画

![image-20241020210203472](images/image-20241020210203472.png)

## 状态转移

![image-20241020211512201](images/image-20241020211512201.png)

## ExitTime

![image-20241020211806838](images/image-20241020211806838.png)

## 状态机API

![image-20241020212029028](images/image-20241020212029028.png)

### 按住不动

![image-20241020212326361](images/image-20241020212326361.png)

## 状态机行为

![image-20241020212753599](images/image-20241020212753599.png)

![image-20241020212826369](images/image-20241020212826369.png)

![image-20241020212928643](images/image-20241020212928643.png)

### 结合ExitTIme 可以在dance退出到idle的时候，用该脚本重置参数

![image-20241020213348913](images/image-20241020213348913.png)

## 精细控制

![image-20241022144006872](images/image-20241022144006872.png)

# 视角跟随

## 方法一：

```c#
ublic class CameraController : MonoBehaviour
{
    public Transform obj;
    private Vector3 distance = new Vector3(0,8,-8);
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = obj.position + distance;
    }
}
```

## 方法二：

将相机作为玩家的子节点 