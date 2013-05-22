maxNumCompThreads(1); format long

% 8x12 matrix T containing runtimes of CountingSort [k=10 10^3 10^5 10^7]:
T = [
0.000015 0.000053 0.000090 0.000421 0.003952 0.042581 0.233628;
0.000015 0.000059 0.000051 0.000339 0.003767 0.041122 0.178244;
0.000014 0.000016 0.000051 0.000373 0.003685 0.037346 0.305188
]';
% where, columns 1..3 correspond to {a,d,u} (k=10), 
%        columns 4..6 correspond to {a,d,u} (k=10^3),
%        columns 7..9 correspond to {a,d,u} (k=10^5), 
%        columns 10..12 correspond to {a,d,u} (k=10^7), 
% Note the use of NaN to indicate missing entries.
T_linear_search = T;


% Run time plot
x_axis = [ 10^2 10^3 10^4 10^5 10^6 10^7 10^8];
figure(1); clf; set(gcf,'Position',[353 601 800 400]);
subplot(121); set(gca,'Position',[0.2 0.10 0.35 0.65]);             % semilog graph
semilogx(x_axis',T(:,1),'ro-',x_axis',T(:,2),'g^-',x_axis',T(:,3),'b*-'); 
set(gca,'XTick',[ 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8]);
xlim([1e+1 1e+8]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
legend('a--linear search (k=10)','d--linear search (k=10)','u--linear search (k=10)'); 
title('T(n) vs. log(n)','FontSize',16);
subplot(122); set(gca,'Position',[0.64 0.10 0.35 0.65]);             % log-log graph
loglog(x_axis',T(:,1),'ro-',x_axis',T(:,2),'g^-',x_axis',T(:,3),'b*-'); 
set(gca,'XTick',[ 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8],...
       'YTick',[1e-6 1e-5 1e-4 1e-3 1e-2 1e-1 1e+0 1e+1 1e+2 1e+3 1e+4]);
set(gca,'DataAspectRatio',[1.4e+8 1e+4 1]);
axis([10^(1) 10^(8) 10^(-6) 10^(4)]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
title('log(T(n)) vs. log(n)','FontSize',16);
print('-depsc',['runtime_linear_search.eps']);

% 8x12 matrix T containing runtimes of CountingSort [k=10 10^3 10^5 10^7]:
T = [
0.000021 0.000022 0.000023 0.000026 0.000040 0.000044 0.000045;
NaN NaN NaN NaN NaN NaN NaN;
NaN NaN NaN NaN NaN NaN NaN;
]';
% where, columns 1..3 correspond to {a,d,u} (k=10), 
%        columns 4..6 correspond to {a,d,u} (k=10^3),
%        columns 7..9 correspond to {a,d,u} (k=10^5), 
%        columns 10..12 correspond to {a,d,u} (k=10^7), 
% Note the use of NaN to indicate missing entries.
T_binary_search = T;


% Run time plot
x_axis = [ 10^2 10^3 10^4 10^5 10^6 10^7 10^8];
figure(2); clf; set(gcf,'Position',[353 601 800 400]);
subplot(121); set(gca,'Position',[0.2 0.10 0.35 0.65]);             % semilog graph
semilogx(x_axis',T(:,1),'ro-',x_axis',T(:,2),'g^-',x_axis',T(:,3),'b*-'); 
set(gca,'XTick',[ 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8]);
xlim([1e+1 1e+8]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
legend('a--binary search (k=10)','d--binary search (k=10)','u--binary search (k=10)'); 
title('T(n) vs. log(n)','FontSize',16);
subplot(122); set(gca,'Position',[0.64 0.10 0.35 0.65]);             % log-log graph
loglog(x_axis',T(:,1),'ro-',x_axis',T(:,2),'g^-',x_axis',T(:,3),'b*-'); 
set(gca,'XTick',[ 1e+2 1e+3 1e+4 1e+5 1e+6 1e+7 1e+8],...
       'YTick',[1e-6 1e-5 1e-4 1e-3 1e-2 1e-1 1e+0 1e+1 1e+2 1e+3 1e+4]);
set(gca,'DataAspectRatio',[1.4e+8 1e+4 1]);
axis([10^(1) 10^(8) 10^(-6) 10^(4)]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
title('log(T(n)) vs. log(n)','FontSize',16);
print('-depsc',['runtime_binary_search.eps']);

% Save mat
save runtime.mat T_linear_search T_binary_search;