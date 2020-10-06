function fitData(X,Y)
  X1 = [ones(length(X),1) X'] %polynomial features
  X2 = [X1 (X.*X)']  %polynomial features
  X3 = [X2 (X.^3)']  %polynomial features
  Y = Y'
  disp('Parameters of Regression');
  Theta1 = pinv(X1'*X1)*(X1'*Y)  %normal equation
  Theta2 = pinv(X2'*X2)*(X2'*Y)  %normal equation
  Theta3 = pinv(X3'*X3)*(X3'*Y)  %normal equation
  
  hold on
  scatter(X,Y);
  plot(X,X1*Theta1) %plot
  plot(X,X2*Theta2)
  plot(X,X3*Theta3)
  legend('Original Points','Linear fit','Quadratic fit','Cubic fit','Location','northwest')
  xlabel('x') %label
  ylabel('y')
  title('Polynomial Regression') %title
  
end
