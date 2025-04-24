#!/bin/sh
content_after_map=./maps/invalid/content_after_map.cub
double_identifier=./maps/invalid/double_identifier.cub
empty_file=./maps/invalid/empty_file.cub
empty_line_in_map=./maps/invalid/empty_line_in_map.cub
empty_file_nl=./maps/invalid/empty_file_nl.cub
file_no_rights=./maps/invalid/file_no_rights.cub
incomplete=./maps/invalid/incomplete.cub
int_max_color=./maps/invalid/int_max_color.cub
int_min_color=./maps/invalid/int_min_color.cub
invalid_color_syntax=./maps/invalid/invalid_color_syntax.cub
invalid_map=./maps/invalid/invalid_map.cub
letter_color=./maps/invalid/letter_color.cub
missing_color_b=./maps/invalid/missing_color_b.cub
missing_color=./maps/invalid/missing_color.cub
missing_texture=./maps/invalid/missing_texture.cub
missing_texture_info=./maps/invalid/missing_texture_info.cub
multiple_players=./maps/invalid/multiple_players.cub
negative_color=./maps/invalid/negative_color.cub
newline_in_map=./maps/invalid/newline_in_map.cub
nl_after_map=./maps/invalid/nl_after_map.cub
no_map=./maps/invalid/no_map.cub
no_player_map=./maps/invalid/no_player_map.cub
non_closed_map_0=./maps/invalid/non_closed_map_0.cub
non_closed_map_1=./maps/invalid/non_closed_map_1.cub
non_closed_map_2=./maps/invalid/non_closed_map_2.cub
non_closed_map_3=./maps/invalid/non_closed_map_3.cub
non_existing_file=./maps/invalid/non_existing_file.cub
not_closed_bottom=./maps/invalid/not_closed_bottom.cub
not_rgb=./maps/invalid/not_rgb.cub
only_map=./maps/invalid/only_map.cub
path_to_directory=./maps/invalid/path_to_directory.cub
texture_after_map=./maps/invalid/texture_after_map.cub
wrong_extension_cu=./maps/invalid/wrong_extension.cu
wrong_extension_cubr=./maps/invalid/wrong_extension.cubr
wrong_identifier_ceiling=./maps/invalid/wrong_identifier_ceiling.cub
wrong_identifier_texture=./maps/invalid/wrong_identifier_texture.cub
wrong_map_content=./maps/invalid/wrong_map_content.cub
wrong_texture_syntax=./maps/invalid/wrong_texture_syntax.cub

ULCYAN="\e[4;96m"
LCYAN="\e[96m"
RES="\e[0m"

./cub3D 1>/dev/null 2>script.out
error="$(cat script.out | grep 'Error' | tr -d '\n')"

testing() {
        echo "${LCYAN}~ Testing...${RES}"
        sleep 0.2
}

result() {
        stderr="$(cat script.out | grep 'Error' | tr -d '\n')"
        if [ "${stderr}" = "${error}" ]
        then
                echo "${LCYAN}~ Result: ✅${RES}"
        else
                echo "${LCYAN}~ Result: ❌${RES}"
        fi
}

echo "\n${ULCYAN}Testing with content after map${RES}"
testing
./cub3D $content_after_map 2>script.out
result

echo "\n${ULCYAN}Testing with double identifier${RES}"
testing
./cub3D $double_identifier 2>script.out
result

echo "\n${ULCYAN}Testing with empty file${RES}"
testing
./cub3D $empty_file 2>script.out
result

echo "\n${ULCYAN}Testing with empty line in map${RES}"
testing
./cub3D $empty_line_in_map 2>script.out
result

echo "\n${ULCYAN}Testing with empty file with newline${RES}"
testing
./cub3D $empty_file_nl 2>script.out
result

#echo "\n${ULCYAN}Testing with file with no rights${RES}"
#testing
#./cub3D $file_no_rights.cub 2>script.out
#result

echo "\n${ULCYAN}Testing with missing map${RES}"
testing
./cub3D $incomplete 2>script.out
result

echo "\n${ULCYAN}Testing with color greater than INT MAX${RES}"
testing
./cub3D $int_max_color 2>script.out
result

echo "\n${ULCYAN}Testing with color less than INT MIN${RES}"
testing
./cub3D $int_min_color 2>script.out
result

echo "\n${ULCYAN}Testing with invalid color syntax${RES}"
testing
./cub3D $invalid_color_syntax 2>script.out
result

echo "\n${ULCYAN}Testing with not closed map top${RES}"
testing
./cub3D $invalid_map 2>script.out
result

echo "\n${ULCYAN}Testing with letter in color${RES}"
testing
./cub3D $letter_color 2>script.out
result

echo "\n${ULCYAN}Testing with missing color B${RES}"
testing
./cub3D $missing_color_b 2>script.out
result

echo "\n${ULCYAN}Testing with missing color identifier${RES}"
testing
./cub3D $missing_color 2>script.out
result

echo "\n${ULCYAN}Testing with missing texture identifier${RES}"
testing
./cub3D $missing_texture 2>script.out
result

echo "\n${ULCYAN}Testing with missing texture info${RES}"
testing
./cub3D $missing_texture_info 2>script.out
result

echo "\n${ULCYAN}Testing with multiple players${RES}"
testing
./cub3D $multiple_players 2>script.out
result

echo "\n${ULCYAN}Testing with negative color${RES}"
testing
./cub3D $negative_color 2>script.out
result

echo "\n${ULCYAN}Testing with newline in map${RES}"
testing
./cub3D $newline_in_map 2>script.out
result

echo "\n${ULCYAN}Testing with newline after map${RES}"
testing
./cub3D $nl_after_map 2>script.out
result

echo "\n${ULCYAN}Testing with no map${RES}"
testing
./cub3D $no_map 2>script.out
result

echo "\n${ULCYAN}Testing with no player in map${RES}"
testing
./cub3D $no_player_map 2>script.out
result

echo "\n${ULCYAN}Testing with non closed maps${RES}"
testing
./cub3D $non_closed_map_0 2>script.out
result
testing
./cub3D $non_closed_map_1 2>script.out
result
testing
./cub3D $non_closed_map_2 2>script.out
result
testing
./cub3D $non_closed_map_3 2>script.out
result

echo "\n${ULCYAN}Testing with non existing texture file${RES}"
testing
./cub3D $non_existing_file 2>script.out
result

echo "\n${ULCYAN}Testing with not closed map bottom${RES}"
testing
./cub3D $not_closed_bottom 2>script.out
result

echo "\n${ULCYAN}Testing with not RGB color${RES}"
testing
./cub3D $not_rgb 2>script.out
result

echo "\n${ULCYAN}Testing with only map${RES}"
testing
./cub3D $only_map 2>script.out
result

echo "\n${ULCYAN}Testing with directory as texture${RES}"
testing
./cub3D $path_to_directory 2>script.out
result

echo "\n${ULCYAN}Testing with texture after map${RES}"
testing
./cub3D $texture_after_map 2>script.out
result

echo "\n${ULCYAN}Testing with wrong extension .cu${RES}"
testing
./cub3D $wrong_extension_cu 2>script.out
result

echo "\n${ULCYAN}Testing with wrong extension .cubr${RES}"
testing
./cub3D $wrong_extension_cubr 2>script.out
result

echo "\n${ULCYAN}Testing with wrong identifier ceiling${RES}"
testing
./cub3D $wrong_identifier_ceiling 2>script.out
result

echo "\n${ULCYAN}Testing with wrong identifier texture${RES}"
testing
./cub3D $wrong_identifier_texture 2>script.out
result

echo "\n${ULCYAN}Testing with wrong map content${RES}"
testing
./cub3D $wrong_map_content 2>script.out
result

echo "\n${ULCYAN}Testing with wrong texture syntax${RES}"
testing
./cub3D $wrong_texture_syntax 2>script.out
result

rm script.out
