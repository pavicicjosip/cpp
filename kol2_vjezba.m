%%
clc 
clear

A = [4 2
    8 3
    8 12];

b = [-1;2;4];

SVD(A,b)

%%
function x = SVD(A,b)
    [U,S,V] = svd(A);
    y = S\(U*b);
    x = V*y;
end

%Ax = b -> x = inv(A'A)*A'b
function x = LPNK_normalne_jedn(A,b)
    x = (A'*A)\(A'*b);
end

%A mora biti pozitivno definitna
function x = metodaKonjugGrad(A,b,x)
    r = b - A*x;
    d = r;
    for k = 1:10
       z = A*d;
       alpha = (r'*r)/(d'*z);
       x = x + alpha*d;
       nazivnik_beta = r'*r;
       r = r - alpha*z;
       beta = (r'*r)/nazivnik_beta;
       d = r + beta*d;
    end
end

%A mora biti pozitivno definitna
function x = metodaNajbrSilaska(A,b,x)
    r = b - A*x;
    for k = 1:10
       z = A*r;
       alpha = (r'*r)/(r'*z);
       x = x + alpha*r;
       r = r - alpha*z;
    end
end


%konvergira za strogo dijagonalo domninantne mat po redcima ili stupcima,
%konvergira za norm(C, bilokoja) < 1
function x = jelMozeJakobijeva(A)
    n = size(A,1);
    L = zeros(n);
    D = zeros(n);
    U = zeros(n);
    for ii = 1:n
        for jj = 1:n
            if ii > jj
               L(ii,jj) = A(ii,jj); 
            elseif ii == jj
               D(ii,ii) = A(ii,ii);     
            else
               U(ii,jj) = A(ii,jj);
            end
        end
    end
    
    M = D;
    N = L+U;
    C = -inv(M)*N;
    
    if norm(C,1) < 1 || norm(C,2) < 1 || norm(C, inf) < 1
       x = "DA"; 
    else
       x = "NE";
    end
end

function x = jakobijeva(A,b,x,epsilon)
    n = size(A,1);
    L = zeros(n);
    D = zeros(n);
    U = zeros(n);
    for ii = 1:n
        for jj = 1:n
            if ii > jj
               L(ii,jj) = A(ii,jj); 
            elseif ii == jj
               D(ii,ii) = A(ii,ii);     
            else
               U(ii,jj) = A(ii,jj);
            end
        end
    end
    
    M = D;
    N = L+U;
    C = -inv(M)*N;
    
    x1 = inv(M)*N*x +inv(M)*b;
    
    k = ceil((1/log10(norm(C, inf)))*log10((epsilon*(1-norm(C,inf)))/(norm(x1-x, inf))))
    
    for ii = 1:k
       x = inv(M)*N*x + inv(M)*b;
    end
    
end

%konvergira za strogo dijagonalo domninantne mat po redcima, mora bit
%kvadratna
function x = jelMozeGaussSeidel(A)
    n = size(A,1);
    x = "da";
    for ii = 1:n
        s = 0;
        for jj = 1:n
            if jj ~= ii
                s = s + abs(A(ii,jj));
            end
        end
        
        if s > abs(A(ii,ii))
            x = "ne";
        end
    end
end

function x = gaussSeidel(A,b,x,epsilon)
    n = size(A,1);
    L = zeros(n);
    D = zeros(n);
    U = zeros(n);
    for ii = 1:n
        for jj = 1:n
            if ii > jj
               L(ii,jj) = A(ii,jj); 
            elseif ii == jj
               D(ii,ii) = A(ii,ii);     
            else
               U(ii,jj) = A(ii,jj);
            end
        end
    end
    
    M = L+D;
    N = U;
    C = -inv(M)*N;
    
    x1 = inv(M)*N*x+inv(M)*b;
    
    k = ceil((1/log10(norm(C,inf)))*log10((epsilon*(1-norm(C,inf)))/(norm(x1-x))));
    
    for ii = 1:k
        x = inv(M)*N*x + inv(M)*b;
    end
end


%nema uvjeta na A osim da je mxn te m>=n
function [Q,R] = QRFAKT(A)
    [m,n] = size(A);
    Q = eye(n);
    R = A;
    for k = 1:n-1
       u = R(k:m,k);
       e1 = zeros(size(u,1),1);
       e1(1) = 1;
       v_ = sign(u(1))*norm(u,2)*e1 + u;
       v = v_/norm(v_,2);
       H_k = eye(m-k+1) - 2*(v*v');
       Q_k = [eye(k-1) zeros(k-1,m-k+1);zeros(m-k+1,k-1)  H_k];
       R = Q_k*R;
       Q = Q*Q_k;
    end
end

%A mora imat sve glavne minore razlicite od 0, mora biti kvadratna
function [L,U] = LUFAKT(A)
    n = size(A,1);
    U = A;
    L = eye(n);
    
    for kk = 1:n-1
        for jj = kk+1:n
            L(jj,kk) = U(jj,kk)/U(kk,kk);
            U(jj,kk:n) = U(jj,kk:n)-L(jj,kk)*U(kk,kk:n);
        end
    end
end

function y = unap(L,b)
    n = size(L,1);
    y = zeros(n,1);
    y(1) = b(1)/L(1,1);
    for ii = 2:n
       y(ii) = (1/L(ii,ii))*(b(ii) - L(ii, 1:ii-1) * y(1:ii-1));
    end
end

function x = povsup(U,b)
    n = size(U,1);
    x = zeros(n,1);
    for ii = n:-1:1
       x(ii) = (1/U(ii,ii))*(b(ii) - U(ii, ii+1:n)*x(ii+1:n)); 
    end
end

















