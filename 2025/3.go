package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func maxAlphaNumericIndex(s string) int {
	max := rune(0)
	max_i := 0
	for i, r := range s {
		if r > max {
			max = r
			max_i = i
		}
	}
	return max_i
}

func Day3() {
	scanner := bufio.NewScanner(os.Stdin)

	p1 := 0

	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)

		ai := maxAlphaNumericIndex(line[:len(line)-1])
		a := rune(line[ai])
		bi := maxAlphaNumericIndex(line[ai+1:]) + ai + 1
		b := rune(line[bi])

		fmt.Printf("\t%c %c\n", a, b)

		combined := string(a) + string(b)
		fmt.Println(combined)

		c, _ := strconv.Atoi(combined)
		p1 += c
	}

	fmt.Printf("Part 1: %d\n", p1)
}

func Day3Part2() {
	scanner := bufio.NewScanner(os.Stdin)

	p2 := 0

	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)
		ai := -1
		combined := ""
		for i := 11; i >= 0; i-- {
			ai = maxAlphaNumericIndex(line[ai+1:len(line)-i]) + ai + 1
			a := rune(line[ai])
			combined += string(a)
		}

		c, _ := strconv.Atoi(combined)
		fmt.Printf("\t%d\n", c)
		p2 += c
	}

	fmt.Printf("Part 2: %d\n", p2)
}
