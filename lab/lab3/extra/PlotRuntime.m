maxNumCompThreads(1); format long

% 8x12 matrix T containing runtimes of CountingSort [k=10 10^3 10^5 10^7]:
T = [;
    ;
    ;
    ;
    ;
    ;
    ;
   ];
% where, columns 1..3 correspond to {a,d,u} (k=10), 
%        columns 4..6 correspond to {a,d,u} (k=10^3),
%        columns 7..9 correspond to {a,d,u} (k=10^5), 
%        columns 10..12 correspond to {a,d,u} (k=10^7), 
% Note the use of NaN to indicate missing entries.
T_countingsort = T;


% Run time plot
x_axis = [10^1 10^2 10^3 10^4 10^5 10^6 10^7 10^8];
figure(2); clf; set(gcf,'Position',[353 601 800 400]);
subplot(121); set(gca,'Position',[0.2 0.10 0.35 0.65]);             % semilog graph
semilogx(x_axis',T(:,1),'bo-',x_axis',T(:,2),'b^-',x_axis',T(:,3),'b*-',...
        x_axis',T(:,4),'ro-',x_axis',T(:,5),'r^-',x_axis',T(:,6),'r*-',...
        x_axis',T(:,7),'go-',x_axis',T(:,8),'g^-',x_axis',T(:,9),'g*-',...
        x_axis',T(:,10),'mo-',x_axis',T(:,11),'m^-',x_axis',T(:,12),'m*-'); 
set(gca,'XTick',[1e+1 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8]);
xlim([1e+1 1e+8]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
legend('a--counting sort (k=10)','d--counting sort (k=10)','u--counting sort (k=10)',...
      'a--counting sort (k=10^3)','d--counting sort (k=10^3)','u--counting sort (k=10^3)',...
      'a--counting sort (k=10^5)','d--counting sort (k=10^5)','u--counting sort (k=10^5)',...
      'a--counting sort (k=10^7)','d--counting sort (k=10^7)','u--counting sort (k=10^7)','Location','NorthWest'); 
title('T(n) vs. log(n)','FontSize',16);
subplot(122); set(gca,'Position',[0.64 0.10 0.35 0.65]);             % log-log graph
loglog(x_axis',T(:,1),'bo-',x_axis',T(:,2),'b^-',x_axis',T(:,3),'b*-',...
      x_axis',T(:,4),'ro-',x_axis',T(:,5),'r^-',x_axis',T(:,6),'r*-',...
      x_axis',T(:,7),'go-',x_axis',T(:,8),'g^-',x_axis',T(:,9),'g*-',...
      x_axis',T(:,10),'mo-',x_axis',T(:,11),'m^-',x_axis',T(:,12),'m*-'); 
set(gca,'XTick',[1e+1 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8],...
       'YTick',[1e-6 1e-5 1e-4 1e-3 1e-2 1e-1 1e+0 1e+1 1e+2 1e+3 1e+4]);
set(gca,'DataAspectRatio',[1.4e+8 1e+4 1]);
axis([10^(1) 10^(8) 10^(-6) 10^(4)]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
title('log(T(n)) vs. log(n)','FontSize',16);
print('-depsc',['runtime_counting.eps']);

% 8x12 matrix T containing runtimes of RadixSort [r=1 5 10 20]:
T = [;
    ;
    ;
    ;
    ;
    ;
    ;
    ]; 
% where, columns 1..3 correspond to {a,d,u} (r=1), 
%        columns 4..6 correspond to {a,d,u} (r=5),
%        columns 7..9 correspond to {a,d,u} (r=10), 
%        columns 10..12 correspond to {a,d,u} (r=20), 
% Note the use of NaN to indicate missing entries.
T_radixsort = T;

x_axis = [10^1 10^2 10^3 10^4 10^5 10^6 10^7 10^8];
figure(2); clf; set(gcf,'Position',[353 601 800 400]);
subplot(121); set(gca,'Position',[0.2 0.10 0.35 0.65]);
semilogx(x_axis',T(:,1),'bo-',x_axis',T(:,2),'b^-',x_axis',T(:,3),'b*-',...
        x_axis',T(:,4),'ro-',x_axis',T(:,5),'r^-',x_axis',T(:,6),'r*-',...
        x_axis',T(:,7),'go-',x_axis',T(:,8),'g^-',x_axis',T(:,9),'g*-',...
        x_axis',T(:,10),'mo-',x_axis',T(:,11),'m^-',x_axis',T(:,12),'m*-'); 
set(gca,'XTick',[1e+1 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8]);
xlim([1e+1 1e+8]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
legend('a--radix sort (r=1)','d--radix sort (r=1)','u--radix sort (r=1)',...
      'a--radix sort (r=5)','d--radix sort (r=5)','u--radix sort (r=5)',...
      'a--radix sort (r=10)','d--radix sort (r=10)','u--radix sort (r=10)',...
      'a--radix sort (r=20)','d--radix sort (r=20)','u--radix sort (r=20)','Location','NorthWest'); 
title('T(n) vs. log(n)','FontSize',16);
subplot(122); set(gca,'Position',[0.64 0.10 0.35 0.65]);
loglog(x_axis',T(:,1),'bo-',x_axis',T(:,2),'b^-',x_axis',T(:,3),'b*-',...
      x_axis',T(:,4),'ro-',x_axis',T(:,5),'r^-',x_axis',T(:,6),'r*-',...
      x_axis',T(:,7),'go-',x_axis',T(:,8),'g^-',x_axis',T(:,9),'g*-',...
      x_axis',T(:,10),'mo-',x_axis',T(:,11),'m^-',x_axis',T(:,12),'m*-'); 
set(gca,'XTick',[1e+1 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8],...
       'YTick',[1e-6 1e-5 1e-4 1e-3 1e-2 1e-1 1e+0 1e+1 1e+2 1e+3 1e+4]);
set(gca,'DataAspectRatio',[1.4e+8 1e+4 1]);
axis([10^(1) 10^(8) 10^(-6) 10^(4)]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
title('log(T(n)) vs. log(n)','FontSize',16);
print('-depsc',['runtime_radix.eps']);

% Save mat
save runtime.mat T_countingsort T_radixsort;