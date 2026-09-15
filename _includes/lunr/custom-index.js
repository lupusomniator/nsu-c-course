// Keep Cyrillic words in the index: Lunr's default trimmer only keeps Latin letters.
if (!this.courseUnicodeSearch) {
  var unicodeTrimmer = function (token) {
    return token.update(function (text) {
      return text.replace(/^[^\p{L}\p{N}_]+|[^\p{L}\p{N}_]+$/gu, '');
    });
  };
  lunr.Pipeline.registerFunction(unicodeTrimmer, 'courseUnicodeTrimmer');
  this.pipeline.reset();
  this.pipeline.add(unicodeTrimmer);
  this.searchPipeline.reset();
  this.courseUnicodeSearch = true;
}
