
CREATE TABLE `fly_student_info`  (
  `id` varchar(36) CHARACTER SET utf8mb4  NOT NULL COMMENT '主键唯一标识',
  `name` varchar(50) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '姓名',
  `school_id` varchar(36) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '所属学校',
  `academy_id` varchar(36) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '所属学院',
  `birthday` varchar(50) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '出生日期',
  `stu_no` varchar(50) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '学号',
  `sex` varchar(1) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '性别',
  `remarks` varchar(255) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '描述',
  `create_time` datetime NULL DEFAULT NULL COMMENT '创建时间',
  `create_user_id` varchar(36) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '创建人ID',
  `create_user` varchar(50) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '创建人',
  `update_time` datetime NULL DEFAULT NULL COMMENT '更新时间',
  `update_user_id` varchar(36) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '更新人ID',
  `update_user` varchar(50) CHARACTER SET utf8mb4  NULL DEFAULT NULL COMMENT '更新人',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COMMENT = '学生信息表' ROW_FORMAT = Dynamic;


INSERT INTO `fly_student_info` (`id`, `name`, `school_id`, `academy_id`, `birthday`, `stu_no`, `sex`, `remarks`, `create_time`, `create_user_id`, `create_user`, `update_time`, `update_user_id`, `update_user`) VALUES ('2c8e60f4d7bf40aeb6c5860fcfc70197', '王朝', '0', '2', '2023-08-15', 'HUBU2023004', '2', '423442222222222222', '2023-08-13 17:58:46', '1', '王大宸', '2023-08-13 18:16:33', '1', '王大宸');
INSERT INTO `fly_student_info` (`id`, `name`, `school_id`, `academy_id`, `birthday`, `stu_no`, `sex`, `remarks`, `create_time`, `create_user_id`, `create_user`, `update_time`, `update_user_id`, `update_user`) VALUES ('465632cf945e4ee4a342dff017cbaddd', '张龙', '0', '2', '2023-08-07', 'HUBU2023002', '1', '123123', '2023-08-13 16:53:55', '1', '王大宸', '2023-08-13 18:16:56', '1', '王大宸');
INSERT INTO `fly_student_info` (`id`, `name`, `school_id`, `academy_id`, `birthday`, `stu_no`, `sex`, `remarks`, `create_time`, `create_user_id`, `create_user`, `update_time`, `update_user_id`, `update_user`) VALUES ('5f025501599042f291d2e4933e1b39fe', '马汉', '0', '3', '2023-08-06', 'HUBU2023003', '2', '11111111111111111111111111111111111', '2023-08-13 17:17:48', '1', '王大宸', '2023-08-13 18:16:44', '1', '王大宸');
INSERT INTO `fly_student_info` (`id`, `name`, `school_id`, `academy_id`, `birthday`, `stu_no`, `sex`, `remarks`, `create_time`, `create_user_id`, `create_user`, `update_time`, `update_user_id`, `update_user`) VALUES ('ba7a90eba3de4607b3d44542eb1d2d24', '赵虎', '0', '1', '2023-08-15', 'HUBU2023001', '1', '123123123', NULL, NULL, NULL, '2023-08-13 18:17:08', '1', '王大宸');


