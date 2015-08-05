#!/usr/bin/python

from string import strip
from sys import stdin

targets = {}
smilies = {'slowdown': '&#9785;' , 'speedup': '&#9786;'}

for line in stdin:
	line = map(strip, filter(None, line.split(' ')))

	if 9 == len(line):
		target, name = line[0:2]
		factor, dir = line[-2:]

		name = name.split('-')
		name, size = '-'.join(name[:-1]), name[-1]

		target_tests = targets.get(target, {})
		name_tests = target_tests.get(name, {})

		name_tests[int(size)] = (factor, dir)
		target_tests[name] = name_tests
		targets[target] = target_tests

print '''\
<html><head>
<title>Performance Changes</title>
<style type="text/css">/*<![CDATA[*/
    body { background: white; color: black; }
    table { border-collapse: collapse; }

    th, td { border: 1px solid silver; padding: 0.2em; }
    td { text-align: center; }
    th:first-child { text-align: left; }
    th { background: #eee; }

 /* those colors also should work for color blinds */
    td.slowdown { background: #f93; }
    td.speedup { background: #6f9; }
/*]]>*/</style>
</head><body>
<h1>Performance Changes</h1>'''

targets = targets.items()
targets.sort(lambda a, b: cmp(a[0], b[0]))

for target, names in targets:
	sizes = {}

	for tests in names.values():
		for size in tests.keys():
			sizes[size] = True	

	sizes = sizes.keys()
	sizes.sort()

	names = names.items()
	names.sort(lambda a, b: cmp(a[0], b[0]))

	print '<h2><a name="%s">%s</a></h2>' % (target, target)
	print '<table><thead><tr><th>&nbsp;</th>'

	for size in sizes:
		print '<th>%s</th>' % size

	print '</tr></thead><tbody>'

	for name, tests in names:
		print '<tr><th>%s</th>' % name
		
		for size in sizes:
			result = tests.get(size)

			if result:
				factor, dir = result
				print '<td class="%s">%s %s</td>' % (
					dir, factor, smilies[dir])

			else:
				print '<td>&nbsp;</td>'

		print '</tr>'


	print '</tbody></table>'

print '</body></html>'
