var titleEl = document.querySelector('[data-cy="question-title"]');
var diffEl = titleEl.nextElementSibling.children[0];
var contentEl = titleEl.parentElement.nextElementSibling.children[0];

var title = titleEl.textContent;
var diff = diffEl.textContent;
var content = contentEl.innerHTML
  .replaceAll("<p>&nbsp;</p>", "")
  .replaceAll("\n\n\n", "\n\n")
  .replaceAll(/<p><strong>(Example \d:)<\/strong><\/p>/gi, `**$1**`)
  .replaceAll("<p><strong>Constraints:</strong></p>", "## Constraints:")
  .replaceAll(/<em>(.+?)<\/em>/gi, `**$1**`)
  .replaceAll(/<code>(.+?)<\/code>/gi, `\`$1\``)
  .replaceAll(/<pre>((.|\n)+?)<\/pre>/gi, `\`\`\`\n$1\`\`\``)
  .replaceAll(/<ul>\n((.|\n)+?)<\/ul>\n?/gi, `$1`)
  .replaceAll(/^[\t ]+<li>(.+)<\/li>/gim, `* $1`)
  .replaceAll(/(<p>.+?)<strong>(.+?)<\/strong>(.+?<\/p>)/gi, `$1**$2**$3`)
  .replaceAll(/<p>(.+?)<\/p>/gi, `$1`)
  .replaceAll(/<strong>(.+?)<\/strong>/gi, `$1`)
  .replaceAll("&lt;", `<`)
  .replaceAll("&gt;", `>`)
  .replaceAll(/`(.*?)(<sup>)(.*?)`/gi, `<code>$1$2$3</code>`);

var md = `# ${title}\n> ${diff}\n\n${content}`;

console.info(md);