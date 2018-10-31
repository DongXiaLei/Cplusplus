#pragma once
void init(); //初始化
void render();//开始渲染
void executeRotateOperation(int x, int y); //执行旋转操作
void executeScaleOperation(float factor); //执行缩放操作
void executeTranslateOperation(int x, int y);//执行平移操作
void getInitPos(int x, int y); //获取鼠标按下时候的坐标
