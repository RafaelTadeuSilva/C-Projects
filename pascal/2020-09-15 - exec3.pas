Program Pzim ;

function EhPrimo(num: integer) : boolean;
var
	retorno : boolean;
	i: integer;
begin
	retorno := true;
	i:= num -1;
	
	while(i>1) do
	begin
		if(num mod i=0) then
		begin
			retorno := false;
			break;
		end;
		i:=i-1;
	
	end;	
		EhPrimo := retorno;
end;
var n:integer;
Begin
	write('Digite um numero');
	readln(n);
	writeln(EhPrimo(n));  
End.