Program Pzim ;
type
	meuArray = array [1..10] of integer;
function maiorValor(vetor : meuArray):integer;
var 
	i: integer;
	maior : integer;
begin
	maior := vetor[1];
	for i:=1 to 10 do
	begin
		if maior < vetor[i] then
			maior := vetor[i];
	end;		
	maiorValor := maior;
end;
var 
	i : integer;
	arr : meuArray;
Begin
  for i:= 1 to 10 do
  	arr[i] := 3*i;
  	
  write('Maior valor do array é: ', maiorValor(arr));
End.