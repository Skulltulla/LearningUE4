# Animation | 0001 | Bone Cube

## 0001_BoneCube.blend

- A two-meter Cube that has no materials was created.
- The Cube was repositioned such that the bottom rests on the origin
- All transformations were applied (CTRL A)

- A Single Bone was added and in Edit Mode its tip was moved up so it touched the top of the cube.
- The Cube was parented to the Single Bone (CTRL P) with Empty Groups
- The four top vertices were assigned to the automatically created "Bone" vertex group.

- The "Armature" object was moved to the collection "Rig"
- The "Cube" object was moved to the collection "Mesh".

- Pose Mode was not used and no keyframes were created

- Finally, the **Send To Unreal** operation was used, which created three assets of the type Skeleton, Skeletal Mesh, and Physics Asset.

## BoneCube (Skeletal Mesh)

This is similar to a Static Mesh except it is a mesh that is rigged with a Skeleton.

It has a **Physics Asset** property that was auto assigned to **Cube_PhysicsAsset**.

## BoneCube_Skeleton (Skeleton)

Contains the bone hierarchy information. There is a single bone titled "Bone".

TODO: Is it possible to influence what the bone name will be?

## BoneCube_PhysicsAsset (Physics Asset)

Contains a Sphere collision that is mapped to the Bone.

Under the **Tools** panel the **Primitive Type** was changed to **Box** and then
**Re-generate Bodies** was pressed.

## BP_BoneCubeActor (Actor)

A new Actor was created and a **Skeletal Mesh Component** was added and
its Skeletal Mesh was assigned to BoneCube.

Also, its **Collision Presets** property defaulted to **NoCollision** and was changed to **Block All**.


