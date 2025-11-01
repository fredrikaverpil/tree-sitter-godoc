package tree_sitter_godoc_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-godoc"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_godoc.Language())
	if language == nil {
		t.Errorf("Error loading Godoc grammar")
	}
}
