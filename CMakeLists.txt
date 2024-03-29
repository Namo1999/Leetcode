cmake_minimum_required(VERSION 3.9)
project(LeetCode)
set(CMAKE_CXX_STANDARD 17)

#链接库
aux_source_directory(leetcode/editor/cn/include LEETCODE)
add_library(leetcode ${LEETCODE})
LINK_LIBRARIES(leetcode)


add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)
add_executable(100-same-tree leetcode/editor/cn/100-same-tree.cpp)
add_executable(2-add-two-numbers leetcode/editor/cn/2-add-two-numbers.cpp)
add_executable(3-longest-substring-without-repeating-characters leetcode/editor/cn/3-longest-substring-without-repeating-characters.cpp)
add_executable(26-remove-duplicates-from-sorted-array leetcode/editor/cn/26-remove-duplicates-from-sorted-array.cpp)
add_executable(704-binary-search leetcode/editor/cn/704-binary-search.cpp)
add_executable(35-search-insert-position leetcode/editor/cn/35-search-insert-position.cpp)
add_executable(27-remove-element leetcode/editor/cn/27-remove-element.cpp)
add_executable(283-move-zeroes leetcode/editor/cn/283-move-zeroes.cpp)
add_executable(844-backspace-string-compare leetcode/editor/cn/844-backspace-string-compare.cpp)
add_executable(977-squares-of-a-sorted-array leetcode/editor/cn/977-squares-of-a-sorted-array.cpp)
add_executable(209-minimum-size-subarray-sum leetcode/editor/cn/209-minimum-size-subarray-sum.cpp)
add_executable(904-fruit-into-baskets leetcode/editor/cn/904-fruit-into-baskets.cpp)
add_executable(76-minimum-window-substring leetcode/editor/cn/76-minimum-window-substring.cpp)
add_executable(59-spiral-matrix-ii leetcode/editor/cn/59-spiral-matrix-ii.cpp)
add_executable(54-spiral-matrix leetcode/editor/cn/54-spiral-matrix.cpp)
add_executable(203-remove-linked-list-elements leetcode/editor/cn/203-remove-linked-list-elements.cpp)
add_executable(707-design-linked-list leetcode/editor/cn/707-design-linked-list.cpp)
add_executable(copy_707 leetcode/editor/cn/copy_707.cpp)
add_executable(206-reverse-linked-list leetcode/editor/cn/206-reverse-linked-list.cpp)
#add_executable(剑指_offer_55_-_i_i-ping-heng-er-cha-shu-lcof leetcode/editor/cn/剑指_offer_55_-_i_i-ping-heng-er-cha-shu-lcof.cpp)
add_executable(24-swap-nodes-in-pairs leetcode/editor/cn/24-swap-nodes-in-pairs.cpp)
add_executable(19-remove-nth-node-from-end-of-list leetcode/editor/cn/19-remove-nth-node-from-end-of-list.cpp)
add_executable(02_07-intersection-of-two-linked-lists-lcci leetcode/editor/cn/面试题-02.07-intersection-of-two-linked-lists-lcci.cpp)
add_executable(142-linked-list-cycle-ii leetcode/editor/cn/142-linked-list-cycle-ii.cpp)
add_executable(242-valid-anagram leetcode/editor/cn/242-valid-anagram.cpp)
add_executable(349-intersection-of-two-arrays leetcode/editor/cn/349-intersection-of-two-arrays.cpp)
add_executable(202-happy-number leetcode/editor/cn/202-happy-number.cpp)
add_executable(454-4sum-ii leetcode/editor/cn/454-4sum-ii.cpp)
add_executable(383-ransom-note leetcode/editor/cn/383-ransom-note.cpp)
add_executable(49-group-anagrams leetcode/editor/cn/49-group-anagrams.cpp)
add_executable(438-find-all-anagrams-in-a-string leetcode/editor/cn/438-find-all-anagrams-in-a-string.cpp)
add_executable(15-3sum leetcode/editor/cn/15-3sum.cpp)
add_executable(18-4sum leetcode/editor/cn/18-4sum.cpp)
add_executable(144-binary-tree-preorder-traversal leetcode/editor/cn/144-binary-tree-preorder-traversal.cpp)
add_executable(145-binary-tree-postorder-traversal leetcode/editor/cn/145-binary-tree-postorder-traversal.cpp)
add_executable(94-binary-tree-inorder-traversal leetcode/editor/cn/94-binary-tree-inorder-traversal.cpp)
add_executable(102-binary-tree-level-order-traversal leetcode/editor/cn/102-binary-tree-level-order-traversal.cpp)
add_executable(107-binary-tree-level-order-traversal-ii leetcode/editor/cn/107-binary-tree-level-order-traversal-ii.cpp)
add_executable(109-convert-sorted-list-to-binary-search-tree leetcode/editor/cn/109-convert-sorted-list-to-binary-search-tree.cpp)
add_executable(199-binary-tree-right-side-view leetcode/editor/cn/199-binary-tree-right-side-view.cpp)
add_executable(637-average-of-levels-in-binary-tree leetcode/editor/cn/637-average-of-levels-in-binary-tree.cpp)
add_executable(429-n-ary-tree-level-order-traversal leetcode/editor/cn/429-n-ary-tree-level-order-traversal.cpp)
add_executable(515-find-largest-value-in-each-tree-row leetcode/editor/cn/515-find-largest-value-in-each-tree-row.cpp)
add_executable(116-populating-next-right-pointers-in-each-node leetcode/editor/cn/116-populating-next-right-pointers-in-each-node.cpp)
add_executable(117-populating-next-right-pointers-in-each-node-ii leetcode/editor/cn/117-populating-next-right-pointers-in-each-node-ii.cpp)
add_executable(104-maximum-depth-of-binary-tree leetcode/editor/cn/104-maximum-depth-of-binary-tree.cpp)
add_executable(111-minimum-depth-of-binary-tree leetcode/editor/cn/111-minimum-depth-of-binary-tree.cpp)
add_executable(226-invert-binary-tree leetcode/editor/cn/226-invert-binary-tree.cpp)
add_executable(101-symmetric-tree leetcode/editor/cn/101-symmetric-tree.cpp)
add_executable(572-subtree-of-another-tree leetcode/editor/cn/572-subtree-of-another-tree.cpp)
add_executable(344-reverse-string leetcode/editor/cn/344-reverse-string.cpp)
add_executable(541-reverse-string-ii leetcode/editor/cn/541-reverse-string-ii.cpp)
add_executable(222-count-complete-tree-nodes leetcode/editor/cn/222-count-complete-tree-nodes.cpp)
add_executable(test leetcode/editor/cn/test.cpp)
add_executable(05-ti-huan-kong-ge-lcof leetcode/editor/cn/05-ti-huan-kong-ge-lcof.cpp)
add_executable(151-reverse-words-in-a-string leetcode/editor/cn/151-reverse-words-in-a-string.cpp)
add_executable(28-implement-strstr leetcode/editor/cn/28-implement-strstr.cpp)
add_executable(nike_huawei_hj01 leetcode/editor/cn/niuke_huawei_hj01.cpp)
add_executable(niuke_huawei_hj02 leetcode/editor/cn/niuke_huawei_hj02.cpp)
add_executable(niuke_huawei_hj04 leetcode/editor/cn/niuke_huawei_hj04.cpp)
add_executable(learn_string_char leetcode/editor/cn/learn_string_char.cpp)
add_executable(niuke_huawei_hj05 leetcode/editor/cn/niuke_huawei_hj05.cpp)
add_executable(niuke_huawei_hj10 leetcode/editor/cn/niuke_huawei_hj10.cpp)
add_executable(niuke_huaweihj11 leetcode/editor/cn/niuke_huaweihj11.cpp)
add_executable(niuke_huawei_hj12 leetcode/editor/cn/niuke_huawei_hj12.cpp)
add_executable(niuke_huaweihj15 leetcode/editor/cn/niuke_huaweihj15.cpp)
add_executable(niuke_huaweihj31 leetcode/editor/cn/niuke_huaweihj31.cpp)
add_executable(learn_stringstream_1 leetcode/editor/cn/learn_stringstream_1.cpp)
add_executable(niuke_huaweihj54 leetcode/editor/cn/niuke_huaweihj54.cpp)

add_executable(110-balanced-binary-tree leetcode/editor/cn/110-balanced-binary-tree.cpp)
add_executable(257-binary-tree-paths leetcode/editor/cn/257-binary-tree-paths.cpp)
add_executable(404-sum-of-left-leaves leetcode/editor/cn/404-sum-of-left-leaves.cpp)
add_executable(513-find-bottom-left-tree-value leetcode/editor/cn/513-find-bottom-left-tree-value.cpp)
add_executable(112-path-sum leetcode/editor/cn/112-path-sum.cpp)
add_executable(113-path-sum-ii leetcode/editor/cn/113-path-sum-ii.cpp)
add_executable(106-construct-binary-tree-from-inorder-and-postorder-traversal leetcode/editor/cn/106-construct-binary-tree-from-inorder-and-postorder-traversal.cpp)
add_executable(105-construct-binary-tree-from-preorder-and-inorder-traversal leetcode/editor/cn/105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp)
add_executable(654-maximum-binary-tree leetcode/editor/cn/654-maximum-binary-tree.cpp)
add_executable(617-merge-two-binary-trees leetcode/editor/cn/617-merge-two-binary-trees.cpp)
add_executable(700-search-in-a-binary-search-tree leetcode/editor/cn/700-search-in-a-binary-search-tree.cpp)
add_executable(98-validate-binary-search-tree leetcode/editor/cn/98-validate-binary-search-tree.cpp)
add_executable(530-minimum-absolute-difference-in-bst leetcode/editor/cn/530-minimum-absolute-difference-in-bst.cpp)
add_executable(501-find-mode-in-binary-search-tree leetcode/editor/cn/501-find-mode-in-binary-search-tree.cpp)
add_executable(236-lowest-common-ancestor-of-a-binary-tree leetcode/editor/cn/236-lowest-common-ancestor-of-a-binary-tree.cpp)
add_executable(77-combinations leetcode/editor/cn/77-combinations.cpp)
add_executable(216-combination-sum-iii leetcode/editor/cn/216-combination-sum-iii.cpp)
add_executable(17-letter-combinations-of-a-phone-number leetcode/editor/cn/17-letter-combinations-of-a-phone-number.cpp)
add_executable(235-lowest-common-ancestor-of-a-binary-search-tree leetcode/editor/cn/235-lowest-common-ancestor-of-a-binary-search-tree.cpp)
add_executable(34-find-first-and-last-position-of-element-in-sorted-array leetcode/editor/cn/34-find-first-and-last-position-of-element-in-sorted-array.cpp)
add_executable(567-permutation-in-string leetcode/editor/cn/567-permutation-in-string.cpp)
add_executable(701-insert-into-a-binary-search-tree leetcode/editor/cn/701-insert-into-a-binary-search-tree.cpp)
add_executable(543-diameter-of-binary-tree leetcode/editor/cn/543-diameter-of-binary-tree.cpp)
add_executable(114-flatten-binary-tree-to-linked-list leetcode/editor/cn/114-flatten-binary-tree-to-linked-list.cpp)
add_executable(889-construct-binary-tree-from-preorder-and-postorder-traversal leetcode/editor/cn/889-construct-binary-tree-from-preorder-and-postorder-traversal.cpp)
add_executable(652-find-duplicate-subtrees leetcode/editor/cn/652-find-duplicate-subtrees.cpp)
add_executable(297-serialize-and-deserialize-binary-tree leetcode/editor/cn/297-serialize-and-deserialize-binary-tree.cpp)
add_executable(912-sort-an-array leetcode/editor/cn/912-sort-an-array.cpp)
add_executable(315-count-of-smaller-numbers-after-self leetcode/editor/cn/315-count-of-smaller-numbers-after-self.cpp)
add_executable(230-kth-smallest-element-in-a-bst leetcode/editor/cn/230-kth-smallest-element-in-a-bst.cpp)
add_executable(538-convert-bst-to-greater-tree leetcode/editor/cn/538-convert-bst-to-greater-tree.cpp)
add_executable(450-delete-node-in-a-bst leetcode/editor/cn/450-delete-node-in-a-bst.cpp)
add_executable(96-unique-binary-search-trees leetcode/editor/cn/96-unique-binary-search-trees.cpp)
add_executable(95-unique-binary-search-trees-ii leetcode/editor/cn/95-unique-binary-search-trees-ii.cpp)
add_executable(39-combination-sum leetcode/editor/cn/39-combination-sum.cpp)
add_executable(40-combination-sum-ii leetcode/editor/cn/40-combination-sum-ii.cpp)
add_executable(455-assign-cookies leetcode/editor/cn/455-assign-cookies.cpp)
add_executable(376-wiggle-subsequence leetcode/editor/cn/376-wiggle-subsequence.cpp)
add_executable(53-maximum-subarray leetcode/editor/cn/53-maximum-subarray.cpp)
add_executable(122-best-time-to-buy-and-sell-stock-ii leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp)
add_executable(55-jump-game leetcode/editor/cn/55-jump-game.cpp)
add_executable(63-unique-paths-ii leetcode/editor/cn/63-unique-paths-ii.cpp)
add_executable(01bag_1 leetcode/editor/cn/01bag_1.cpp)

add_executable(131-palindrome-partitioning leetcode/editor/cn/131-palindrome-partitioning.cpp)
add_executable(93-restore-ip-addresses leetcode/editor/cn/93-restore-ip-addresses.cpp)
add_executable(78-subsets leetcode/editor/cn/78-subsets.cpp)
add_executable(90-subsets-ii leetcode/editor/cn/90-subsets-ii.cpp)
add_executable(491-increasing-subsequences leetcode/editor/cn/491-increasing-subsequences.cpp)
add_executable(46-permutations leetcode/editor/cn/46-permutations.cpp)
add_executable(47-permutations-ii leetcode/editor/cn/47-permutations-ii.cpp)
add_executable(332-reconstruct-itinerary leetcode/editor/cn/332-reconstruct-itinerary.cpp)
add_executable(51-n-queens leetcode/editor/cn/51-n-queens.cpp)
add_executable(37-sudoku-solver leetcode/editor/cn/37-sudoku-solver.cpp)
add_executable(45-jump-game-ii leetcode/editor/cn/45-jump-game-ii.cpp)
add_executable(1005-maximize-sum-of-array-after-k-negations leetcode/editor/cn/1005-maximize-sum-of-array-after-k-negations.cpp)
add_executable(134-gas-station leetcode/editor/cn/134-gas-station.cpp)
add_executable(135-candy leetcode/editor/cn/135-candy.cpp)
add_executable(860-lemonade-change leetcode/editor/cn/860-lemonade-change.cpp)
add_executable(406-queue-reconstruction-by-height leetcode/editor/cn/406-queue-reconstruction-by-height.cpp)
add_executable(452-minimum-number-of-arrows-to-burst-balloons leetcode/editor/cn/452-minimum-number-of-arrows-to-burst-balloons.cpp)
add_executable(435-non-overlapping-intervals leetcode/editor/cn/435-non-overlapping-intervals.cpp)
add_executable(763-partition-labels leetcode/editor/cn/763-partition-labels.cpp)
add_executable(56-merge-intervals leetcode/editor/cn/56-merge-intervals.cpp)
add_executable(738-monotone-increasing-digits leetcode/editor/cn/738-monotone-increasing-digits.cpp)
add_executable(714-best-time-to-buy-and-sell-stock-with-transaction-fee leetcode/editor/cn/714-best-time-to-buy-and-sell-stock-with-transaction-fee.cpp)
add_executable(345-reverse-vowels-of-a-string leetcode/editor/cn/345-reverse-vowels-of-a-string.cpp)
add_executable(968-binary-tree-cameras leetcode/editor/cn/968-binary-tree-cameras.cpp)
add_executable(509-fibonacci-number leetcode/editor/cn/509-fibonacci-number.cpp)
add_executable(70-climbing-stairs leetcode/editor/cn/70-climbing-stairs.cpp)
add_executable(746-min-cost-climbing-stairs leetcode/editor/cn/746-min-cost-climbing-stairs.cpp)
add_executable(62-unique-paths leetcode/editor/cn/62-unique-paths.cpp)
add_executable(343-integer-break leetcode/editor/cn/343-integer-break.cpp)
add_executable(416-partition-equal-subset-sum leetcode/editor/cn/416-partition-equal-subset-sum.cpp)
add_executable(1049-last-stone-weight-ii leetcode/editor/cn/1049-last-stone-weight-ii.cpp)
add_executable(494-target-sum leetcode/editor/cn/494-target-sum.cpp)
add_executable(474-ones-and-zeroes leetcode/editor/cn/474-ones-and-zeroes.cpp)
add_executable(test_2 leetcode/editor/cn/test_2.cpp)
add_executable(20-valid-parentheses leetcode/editor/cn/20-valid-parentheses.cpp)
add_executable(21-merge-two-sorted-lists leetcode/editor/cn/21-merge-two-sorted-lists.cpp)
add_executable(tetst leetcode/editor/cn/tetst.cpp)
add_executable(wq_bag leetcode/editor/cn/wq_bag.cpp)
add_executable(code_1 leetcode/editor/cn/code_1.cpp)
add_executable(code_2 leetcode/editor/cn/code_2.cpp)
add_executable(23-merge-k-sorted-lists leetcode/editor/cn/23-merge-k-sorted-lists.cpp)
add_executable(227-basic-calculator-ii leetcode/editor/cn/227-basic-calculator-ii.cpp)
add_executable(224-basic-calculator leetcode/editor/cn/224-basic-calculator.cpp)
add_executable(cal-772 leetcode/editor/cn/cal-772.cpp)
add_executable(1143-longest-common-subsequence leetcode/editor/cn/1143-longest-common-subsequence.cpp)
add_executable(code_3 leetcode/editor/cn/code_3.cpp)
add_executable(code_4 leetcode/editor/cn/code_4.cpp)
add_executable(931-minimum-falling-path-sum leetcode/editor/cn/931-minimum-falling-path-sum.cpp)
add_executable(120-triangle leetcode/editor/cn/120-triangle.cpp)
add_executable(1289-minimum-falling-path-sum-ii leetcode/editor/cn/1289-minimum-falling-path-sum-ii.cpp)
add_executable(1575-count-all-possible-routes leetcode/editor/cn/1575-count-all-possible-routes.cpp)
add_executable(code_5 leetcode/editor/cn/code_5.cpp)
add_executable(code_6 leetcode/editor/cn/code_6.cpp)
add_executable(29-divide-two-integers leetcode/editor/cn/29-divide-two-integers.cpp)
add_executable(4-median-of-two-sorted-arrays leetcode/editor/cn/4-median-of-two-sorted-arrays.cpp)
add_executable(5-longest-palindromic-substring leetcode/editor/cn/5-longest-palindromic-substring.cpp)
add_executable(33-search-in-rotated-sorted-array leetcode/editor/cn/33-search-in-rotated-sorted-array.cpp)
add_executable(69-sqrtx leetcode/editor/cn/69-sqrtx.cpp)
add_executable(74-search-a-2d-matrix leetcode/editor/cn/74-search-a-2d-matrix.cpp)
add_executable(162-find-peak-element leetcode/editor/cn/162-find-peak-element.cpp)
add_executable(88-merge-sorted-array leetcode/editor/cn/88-merge-sorted-array.cpp)
add_executable(86-partition-list leetcode/editor/cn/86-partition-list.cpp)
add_executable(learn_prio_queue leetcode/editor/cn/learn_prio_queue.cpp)
add_executable(_l_c_r_057-7WqeDu leetcode/editor/cn/_l_c_r_057-7WqeDu.cpp)