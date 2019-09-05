in_image=imread('2.png');
imshow(in_image);
a=0.05;% a--�ǵ������Ӧ��ȡֵ��Χ��0.04~0.06
I=double(in_image);

%����xy�����ݶ�
fx=[-1,0,1];%x�����ݶ�ģ��
Ix=filter2(fx,I);%x�����˲�
fy=[-1;0;1];%y�����ݶ�ģ��(ע���Ƿֺ�)
Iy=filter2(fy,I);
%�������������ݶȵĳ˻�
Ix2=Ix.^2;
Iy2=Iy.^2;
Ixy=Ix.*Iy;
%ʹ�ø�˹��Ȩ�������ݶȳ˻����м�Ȩ
%����һ��5*5�ĸ�˹��������sigmaֵΪ2
h=fspecial('gaussian',[5,5],2);
IX2=filter2(h,Ix2);
IY2=filter2(h,Iy2);
IXY=filter2(h,Ixy);
%%%%%����ÿ����Ԫ��Harris��Ӧֵ%%%%%
[height,width]=size(I);
R=zeros(height,width);
%��������(i,j)���Ľǵ���
for i=1:height
    for j=1:width
        M=[IX2(i,j) IXY(i,j);IXY(i,j) IY2(i,j)];
        R(i,j)=det(M)-a*(trace(M))^2;
    end
end
clims=[min(min(R)),0.2*max(max(R))];
figure,imagesc(R,clims);




