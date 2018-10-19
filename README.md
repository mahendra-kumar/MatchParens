# MatchParens
Remove unmatched parens from a string

# Description

A question asked during a interview to be solved in ~30 minutes online over phone, so "silent" thinking was not possible.
Later when I thought about this problem, I realized that many IDEs like XCode and VS keep a track of matching parens in the editor, so a fast and quick to update solution must be possible, such as in linear or nlog(n) time. In this implementation std::map is used so complexity is nlog(n) but if substituted with std::unordered_map, it should be linear in average case.

