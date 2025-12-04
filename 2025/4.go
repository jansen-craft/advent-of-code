package main

import (
	"bufio"
	"fmt"
	"os"
)

func accessible(x, y int, diagram [][]rune) bool {
	if x < 0 || y < 0 || x >= len(diagram) || y >= len(diagram[x]) {
		return false
	}
	if diagram[x][y] != '@' {
		return false
	}

	directions := [][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
	adjacentRolls := 0
	for _, dir := range directions {
		nx, ny := x, y
		nx += dir[0]
		ny += dir[1]

		if nx < 0 || nx >= len(diagram) {
			continue
		}
		if ny < 0 || ny >= len(diagram[nx]) {
			continue
		}
		if diagram[nx][ny] == '@' {
			adjacentRolls++
		}
	}
	return adjacentRolls < 4
}

func removeRolls(diagram [][]rune) (int, [][]rune) {
	rollsRemoved := 0
	for i := 0; i < len(diagram); i++ {
		for j := 0; j < len(diagram[i]); j++ {
			if diagram[i][j] != '@' {
				continue
			}
			if accessible(i, j, diagram) {
				rollsRemoved++
				diagram[i][j] = '.'
			}
		}
	}
	return rollsRemoved, diagram
}

func Day4() {
	var diagram [][]rune

	scanner := bufio.NewScanner(os.Stdin)

	p1 := 0
	p2 := 0

	for scanner.Scan() {
		line := scanner.Text()
		diagram = append(diagram, []rune(line))
	}

	firstPass := true
	for {
		rollsRemoved := 0
		rollsRemoved, diagram = removeRolls(diagram)
		if firstPass {
			p1 = rollsRemoved
			firstPass = false
		}
		p2 += rollsRemoved
		if rollsRemoved == 0 {
			break
		}
	}

	fmt.Printf("p1: %d\n", p1)
	fmt.Printf("p2: %d\n", p2)
}
