<?php

$tab = ["rock", "paper", "scissors"];

echo "Choose rock, paper, or scissors: ";
fscanf(STDIN, "%s\n", $input);

$choose = rand(0,2);
$input = strtolower($input);

if ($input == $tab[$choose])
	echo "Tie, The computer also choose $input\n";
elseif ($input == "rock" && $tab[$choose] == "scissors")
	echo "Congratulations! You won! The computer chose $tab[$choose]\n";
elseif ($input == "paper" && $tab[$choose] == "rock")
	echo "Congratulations! You won! The computer chose $tab[$choose]\n";
else
	echo "Sorry, you lost. The computer chose $tab[$choose]\n";
?>
