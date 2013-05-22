sort_method = 'quicksort';
% 7x3 matrix T containing runtimes of your sorting algorithm
T = [NaN NaN NaN NaN NaN NaN NaN;
     NaN NaN NaN NaN NaN NaN NaN;
     NaN NaN NaN NaN NaN NaN NaN]';
% where, rows 1..3 correspond to {a,d,u}
% Note the use of NaN to indicate missing entries.

% Run time plot
x_axis = [10^2 10^3 10^4 10^5 10^6 10^7 10^8];
figure(2); clf; set(gcf,'Position',[353 601 800 400]);

subplot(121); set(gca,'Position',[0.2 0.10 0.35 0.65]);             % semilog graph
semilogx(x_axis',T(:,1),'bo-',x_axis',T(:,2),'r^-',x_axis',T(:,3),'g*-'); 
set(gca,'XTick',x_axis);
xlim([min(x_axis) max(x_axis)]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
legend(['a--' sort_method 'sort'],['d--' sort_method 'sort'],['u--' sort_method 'sort'],'Location','NorthWest'); 
title('T(n) vs. log(n)','FontSize',16);

subplot(122); set(gca,'Position',[0.64 0.10 0.35 0.65]);             % log-log graph
loglog(x_axis',T(:,1),'bo-',x_axis',T(:,2),'r^-',x_axis',T(:,3),'g*-'); 
set(gca,'XTick',x_axis,...
       'YTick',[1e-6 1e-5 1e-4 1e-3 1e-2 1e-1 1e+0 1e+1 1e+2 1e+3 1e+4]);
set(gca,'DataAspectRatio',[1.4e+8 1e+4 1]);
axis([min(x_axis) max(x_axis) 10^(-6) 10^(4)]);
xlabel('n','FontSize',16); ylabel('time (sec)','FontSize',16);
title('log(T(n)) vs. log(n)','FontSize',16);
print('-depsc',['runtime_' sort_method '.eps']);