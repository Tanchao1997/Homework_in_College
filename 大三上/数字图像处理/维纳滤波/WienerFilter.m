I=imread('2.png');
subplot(1,3,1),imshow(I);title('原图');
[m,n]=size(I);
F=fftshift(fft2(I));
k=0.005;
for u=1:m
    for v= 1:n
         H(u,v)=exp((-k)*(((u-m/2)^2+(v-n/2)^2)^(5/6)));
    end
end
G=F.*H;
I0=real(ifft2(ifftshift(G)));
I1=imnoise(uint8(I0),'gaussian',0,0.001);
subplot(1,3,2),imshow(uint8(I1));title('模糊和添加噪声后的图像');
F0=fftshift(fft2(I1));%傅里叶变换
K=0.1;
for u=1:m
    for v=1:n
        H0(u,v)=(abs(H(u,v)))^2;
        H1(u,v)=H0(u,v)./(H(u,v)*(H0(u,v)+K));%维纳滤波
    end
end
F2=H1.*F0;
I2=ifft2(ifftshift(F2));%傅里叶逆变换
subplot(1,3,3),imshow(uint8(I2));title('维纳滤波复原图像');

