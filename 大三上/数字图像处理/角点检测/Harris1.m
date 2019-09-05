in_image=imread('2.png');
imshow(in_image);
a=0.05;% a--角点参数响应，取值范围：0.04~0.06
I=double(in_image);

%计算xy方向梯度
fx=[-1,0,1];%x方向梯度模板
Ix=filter2(fx,I);%x方向滤波
fy=[-1;0;1];%y方向梯度模板(注意是分号)
Iy=filter2(fy,I);
%计算两个方向梯度的乘积
Ix2=Ix.^2;
Iy2=Iy.^2;
Ixy=Ix.*Iy;
%使用高斯加权函数对梯度乘积进行加权
%产生一个5*5的高斯窗函数，sigma值为2
h=fspecial('gaussian',[5,5],2);
IX2=filter2(h,Ix2);
IY2=filter2(h,Iy2);
IXY=filter2(h,Ixy);
%%%%%计算每个像元的Harris响应值%%%%%
[height,width]=size(I);
R=zeros(height,width);
%计算像素(i,j)处的角点性
for i=1:height
    for j=1:width
        M=[IX2(i,j) IXY(i,j);IXY(i,j) IY2(i,j)];
        R(i,j)=det(M)-a*(trace(M))^2;
    end
end
clims=[min(min(R)),0.2*max(max(R))];
figure,imagesc(R,clims);




