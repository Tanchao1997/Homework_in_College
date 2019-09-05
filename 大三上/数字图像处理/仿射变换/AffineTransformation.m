im=imread('2.png');
imshow(im);
alpha=30*pi/180;
R=[cos(alpha), -sin(alpha);sin(alpha),cos(alpha);]*[0.5,0;0,1;];
R=R';
sz=size(im);
h=sz(1);
w=sz(2);
center1=[h;w;]/2;
hh = floor(w*sin(alpha)+h*cos(alpha))+1;
ww = floor(w*cos(alpha)+h*sin(alpha))+1;
center2 = [hh; ww] / 2;
im2=uint8(ones(hh,ww)*128);
   for i=1:hh
       for j=1:ww
           p=[i;j];
           pp=round(R*(p-center2)+center1);
           if(pp(1)>=1&&pp(1)<=h&&pp(2)>=1&&pp(2)<=w)
               im2(i,j)=im(pp(1),pp(2));
           end
       end
   end
   figure,
   imshow(im2);
    