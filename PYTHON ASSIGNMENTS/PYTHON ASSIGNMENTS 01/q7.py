import os

def findFiles(walk_dir):
	for root, subdirs, files in os.walk(walk_dir):
		for filename in files:
			file_path = os.path.join(root, filename)
			print('\t- file %s (full path: %s)' % (filename, file_path))

		for subdir in subdirs:
			print('\t- Subdirectory ' + subdir)
			findFiles (os.path.join(root, subdir))


walk_dir = os.path.dirname('./')

print('Walking Directory = ' + walk_dir)
findFiles(walk_dir)