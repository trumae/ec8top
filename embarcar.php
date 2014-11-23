<?php

$arquivo = file("index.html");

// imprime linha por linha ate detectar o final
echo "<textarea style='width:100%;height:100%;scroll'>";
foreach ($arquivo as $line) {
		$ln= str_replace("\\","\\\\",$line);
		$ln= str_replace("\"","\\\"",$ln);
		$ln= str_replace("%","%%",$ln);
		echo "\"".trim($ln)."\\r\\n\"\n";
}
echo "</textarea>";
?>