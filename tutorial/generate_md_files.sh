#!/bin/bash

# Initialize Markdown files based on a list of filenames in the argument. It also uses the file "TemplateOfChapter.md" as a content template;

# Check if the template file exists
if [ ! -f "TemplateOfChapter.md" ]; then
    echo "Error: TemplateOfChapter.md does not exist."
    exit 1
fi

# Iterate over each filename provided as an argument to the script
for filename in "$@"; do
    # Create/Overwrite the file with the title (filename without extension)
    title="${filename%.*}" 
    echo "# $title" > "$filename.md"
    
    # Append the content of the template to the file
    cat "TemplateOfChapter.md" >> "$filename.md"
	
    # Append link to this file to "Overview.md"
    echo "* [$filename]($filename.md)" >> "Overview.md"
	
done

echo "Files have been generated."

