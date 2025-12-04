package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isNice(s string) bool {
	vowels := "aeiou"
	hasDouble := false
	badSubstrings := []string{"ab", "cd", "pq", "xy"}
	vowelCount := 0

	for i := 0; i < len(s); i++ {
		if i > 0 && s[i] == s[i-1] {
			hasDouble = true
		}
		if strings.ContainsRune(vowels, rune(s[i])) {
			vowelCount++
		}
	}

	for _, bad := range badSubstrings {
		if strings.Contains(s, bad) {
			return false
		}
	}

	return hasDouble && vowelCount >= 3

}

func isNice2(s string) bool {
	pairIndex := make(map[string]int)
	validPair := false
	hasRepeat := false

	for i := 0; i < len(s)-1; i++ {
		pair := s[i : i+2] // add to list of pairs

		previousIndex, exists := pairIndex[pair]
		if exists {
			if i-previousIndex > 1 { // not overlapping
				validPair = true
			}
		} else {
			pairIndex[pair] = i
		}

		if i > 0 && s[i+1] == s[i-1] {
			hasRepeat = true
		}
	}

	return validPair && hasRepeat
}

func Day5() {
	scanner := bufio.NewScanner(os.Stdin)

	p1 := 0
	p2 := 0

	for scanner.Scan() {
		line := scanner.Text()

		if isNice(line) {
			p1++
		}

		if isNice2(line) {
			p2++
		}
	}

	fmt.Printf("p1: %d\n", p1)
	fmt.Printf("p2: %d\n", p2)
}
