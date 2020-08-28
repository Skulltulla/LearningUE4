# Design Notes

## Files
### PLUGINTITLE_APL.xml
A file that exists in the same location as the plugin's Build.cs. To use the file, Build.cs is updated by adding it as a receipt property.

todo:
- minimal content required
- GameActivity.java additions, etc

```
    <gameActivityImportAdditions>
        <insert></insert>
    </gameActivityImportAdditions>

    <gameActivityClassAdditions>
        <insert></insert>
    </gameActivityClassAdditions>
```

References:
- https://stackoverflow.com/questions/40153299/use-apl-android-programming-language-to-make-android-plugin-to-unreal-engine-4