Inflection aware translation library.

To get translated sentence following steps happen:

1. You pass message identifier with appropriate parameters  
 `t.translate("a {age} {animal}", {{"age", {"young"}},{"animal",{"roe deer"}}})`

2. Grammatical categories are calculated <br>  
 in Polish, roe deer have *feminine* gender

3. Sentence template is selected based on results from previous step

4. Word forms used in sentence are chosen.  
 gender of adjective must match noun, so feminine form is chosen: *młoda*

5. Sentence template is filed with final word forms.

You can look on examples to understand better.
