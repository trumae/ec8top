<?php
/*
Atribua o caminho de seu arquivo a uma variável usando a linha de código abaixo.
Substitua a string dentro das aspas pelo caminho para sua imagem no servidor Web.
*/
$nome="04";
$image=$nome.".png";
//$image="01.png";

/*
Extraia os dados de seu arquivo para uma variável. O uso da tag 'rb' informa que deve ser lido como binário.
Adicione as linhas de código a seguir em seu arquivo.
*/
$data = fopen ($image, 'rb'); 
$size=filesize ($image);
$contents= fread ($data, $size);
fclose ($data);

/*
Codifique o conteúdo de seu arquivo, agora armazenado na variável $contents.
Insira a linha de código a seguir e sua imagem será uma string binária, armazenada na variável $encoded.
Agora você pode salvar essa string em um banco de dados para facilitar o armazenamento, passar a variável para edição ou exibi-la.
*/

//encoded= imagem codificada
$encoded= base64_encode($contents);
$ln= str_replace("\\","\\\\",$encoded);
$ln= str_replace("\"","\\\"",$ln);
$ln= str_replace("%","%%",$ln);

//para testar descomente as proximas 2 linhas 
//header("Content-Type: image/jpeg");
//echo $contents;
//-----------------------------------------

//desencoded= imagem descodificada
//$desencoded= base64_decode($encoded);

echo "<textarea style='width:100%;height:100%;scroll'>";
echo "int img".$nome."(char *b, size_t s){\n";
echo "\n";
echo "    //buffer que conterá o texto\n";
echo "    char buffer[TAMBUFF];\n";
echo "    buffer[0] = '\\x0';\n";
echo "\n";
echo "    //codigo binario embarcado da imagem\n";
echo "    strncpy(buffer,\n";
echo "\"".trim($ln)."\"\n";
echo "	,sizeof(buffer));\n";
echo "\n";
echo "	strncat(b, buffer, s);  \n";
echo "    //retorna sucesso\n";
echo "    return 1;\n";
echo "}\n";
echo "</textarea>";
